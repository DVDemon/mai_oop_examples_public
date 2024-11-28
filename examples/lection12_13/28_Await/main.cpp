#include <coroutine>
#include <chrono>
#include <iostream>
#include <functional>
#include <string>
#include <stdexcept>
#include <atomic>
#include <thread>
class Event
{
public:
    Event() = default;
    Event(const Event &) = delete;
    Event(Event &&) = delete;
    Event &operator=(const Event &) = delete;
    Event &operator=(Event &&) = delete;
    class Awaiter;
    Awaiter operator co_await() const noexcept;
    void notify() noexcept;
private:
    friend class Awaiter;
    mutable std::atomic<void *> suspendedWaiter{nullptr};
    mutable std::atomic<bool> notified{false};
};

class Event::Awaiter
{
public:
    Awaiter(const Event &eve) : event(eve) {}
    bool await_ready() const;
    bool await_suspend(std::coroutine_handle<> corHandle) noexcept;
    void await_resume() noexcept {}

private:
    friend class Event;
    const Event &event;
    std::coroutine_handle<> coroutineHandle;
};

bool Event::Awaiter::await_ready() const
{
    if (event.suspendedWaiter.load() != nullptr)
    {
        throw std::runtime_error("More than one waiter is not valid");
    }
    return event.notified;
}
bool Event::Awaiter::await_suspend(std::coroutine_handle<> corHandle) noexcept
{
    coroutineHandle = corHandle;
    if (event.notified)
        return false;
    event.suspendedWaiter.store(this);
    return true;
}
void Event::notify() noexcept
{
    notified = true;
    auto *waiter = static_cast<Awaiter *>(suspendedWaiter.load());
    if (waiter != nullptr)
    {
        waiter->coroutineHandle.resume();
    }
}
Event::Awaiter Event::operator co_await() const noexcept
{
    return Awaiter{*this};
}
struct Task
{
    struct promise_type
    {
        Task get_return_object() { return {}; }
        std::suspend_never initial_suspend() { return {}; }
        std::suspend_never final_suspend() noexcept { return {}; }
        void return_void() {}
        void unhandled_exception() {}
    };
};

Task receiver(Event &event)
{
    auto start = std::chrono::high_resolution_clock::now();
    co_await event;
    std::cout << "Got  the  notification!  " << '\n';
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Waited  " << elapsed.count() << "  seconds." << '\n';
}

using namespace std::chrono_literals;

int main()
{
    std::cout << '\n';
    std::cout << "Notification  before  waiting" << '\n';
    Event event1{};
    auto senderThread1 = std::thread([&event1]
                                     { event1.notify(); }); // Notification
    auto receiverThread1 = std::thread(receiver, std::ref(event1));
    receiverThread1.join();
    senderThread1.join();
    std::cout << '\n';
    std::cout << "Notification  after2seconds  waiting" << '\n';
    Event event2{};
    auto receiverThread2 = std::thread(receiver, std::ref(event2));
    auto senderThread2 = std::thread([&event2]
                                     {
                                    std::this_thread::sleep_for(2s);
                                    event2.notify(); });
    receiverThread2.join();
    senderThread2.join();
    std::cout << '\n';
}
#include <atomic>
#include <chrono>
#include <coroutine>
#include <functional>
#include <iostream>
#include <stdexcept>
#include <string>
#include <thread>
class Event {
public:
  Event() = default;
  Event(const Event &) = delete;
  Event(Event &&) = delete;
  Event &operator=(const Event &) = delete;
  Event &operator=(Event &&) = delete;
  class Awaiter {
  public:
    Awaiter(const Event &eve) : event(eve) {}
    bool await_ready() const {
      if (event.suspendedWaiter.load() != nullptr) {
        throw std::runtime_error("More than one waiter is not valid");
      }
      return event.notified;
    }
    bool await_suspend(std::coroutine_handle<> corHandle) noexcept {
      coroutineHandle = corHandle;
      if (event.notified)
        return false;
      event.suspendedWaiter.store(this);
      return true;
    }
    void await_resume() noexcept {}

  private:
    friend class Event;
    const Event &event;
    std::coroutine_handle<> coroutineHandle;
  };

  Awaiter operator co_await() const noexcept { return Awaiter{*this}; }
  void notify() noexcept {
    notified = true;
    auto *waiter = suspendedWaiter.load();
    if (waiter != nullptr) {
      waiter->coroutineHandle.resume();
    }
  }

private:
  friend class Awaiter;
  mutable std::atomic<Awaiter *> suspendedWaiter{nullptr};
  mutable std::atomic<bool> notified{false};
};

// coroutine
struct Task {
  struct promise_type {
    Task get_return_object() { return {}; }
    std::suspend_never initial_suspend() { return {}; }
    std::suspend_never final_suspend() noexcept { return {}; }
    void return_void() {}
    void unhandled_exception() {}
  };
};

Task receiver(Event &event) {
  auto start = std::chrono::high_resolution_clock::now();
  co_await event;
  std::cout << "Got  the  notification!  " << '\n';
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed = end - start;
  std::cout << "Waited  " << elapsed.count() << "  seconds." << '\n';
}

using namespace std::chrono_literals;

int main() {

  std::cout << "Notification  after2seconds  waiting" << '\n';
  Event event{};
  auto receiverThread = std::thread(receiver, std::ref(event));

  std::this_thread::sleep_for(2s);
  event.notify();

  receiverThread.join();

  std::cout << '\n';
}
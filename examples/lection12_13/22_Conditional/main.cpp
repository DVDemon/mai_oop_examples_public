#include <iostream>           // std::cout
#include <thread>             // std::thread
#include <mutex>              // std::mutex, std::unique_lock
#include <condition_variable> // std::condition_variable
#include <sstream>

struct print : std::stringstream
{
    ~print()
    {
        static std::mutex mtx;
        std::lock_guard<std::mutex> lck(mtx);
        std::cout << this->str();
        std::cout.flush();
    }
};

std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void print_id(int id)
{
    std::unique_lock<std::mutex> lck(mtx); // lock
    print() << "Ready:" << id << std::endl;
    //while (!ready)
        cv.wait(lck); // unlock?
    print() << "thread " << id << std::endl;
}

void go()
{
    std::unique_lock<std::mutex> lck(mtx); // lock
    //ready = true;
    //cv.notify_one();
    cv.notify_all(); // unlock all?
}

int main()
{
    std::thread threads[10];
    // spawn 10 threads:
    for (int i = 0; i < 10; ++i)
        threads[i] = std::thread(print_id, i);

    std::cout << "10 threads ready to race...\n";
    std::cin.get();
    go(); // go!

    for (auto &th : threads)
        th.join();

    return 0;
}
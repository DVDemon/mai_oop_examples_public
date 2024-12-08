#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>
#include <condition_variable>
#include <vector>

class Counter {
private:
    int value;
    std::atomic_int value_a;
public:

    Counter() : value(0), value_a(0) {

    }

    int get() {
        return value;
    }

    int get_a() {
        return value_a.load();
    }

    int increment_atomic() {
        int v = value_a.load();
        while (!value_a.compare_exchange_weak(v, value + 1));
        return value_a.load();
    }

    int increment() {
        value = value+1;
        return value;
    }
    
    int decrement() {
        value = value-1;
        return value;
    }
};

int main(int argc, char** argv) {

    std::vector<std::thread> threads;
    std::mutex mtx;
    std::condition_variable cv;
    Counter cnt;

    for (int i = 0; i < 100; i++)
        threads.emplace_back([&mtx,&cv,&cnt](bool inc)
                            {
                                std::cout << "thread ready ..." << std::endl;
                                std::unique_lock<std::mutex> lock(mtx);
                                cv.wait(lock);

                                for (int i = 0; i < 1000000; i++) 
                                    if(inc) cnt.increment();
                                    else cnt.decrement();
                                std::cout << "thread done" << std::endl;
                            }, i%2);

    {
        std::cout << "Press any key" << std::endl;
        std::cin.get();
        std::unique_lock<std::mutex> lock(mtx);
        cv.notify_all();
    }

    for (auto& a : threads) a.join();
    std::cout << "Result:" << cnt.get() << std::endl;
    return 0;
}


#include <iostream>
#include <thread>
#include <vector>
#include <cmath>
#include <chrono>

class Scoped_Thread {
    std::thread t;
public:

    Scoped_Thread(std::thread&& t_) : t(std::move(t_)) {
        if (!t.joinable()) throw std::logic_error("No thread");
    };

    Scoped_Thread(std::thread& t_) : t(std::move(t_)) {
        if (!t.joinable()) throw std::logic_error("No thread");
    };

    // выглядит как конструктор копирования, а на самом деле - перемещения

    Scoped_Thread(Scoped_Thread & other) : t(std::move(other.t)) {
    };
    Scoped_Thread(Scoped_Thread && other) noexcept : t(std::move(other.t)) {
    };
    // оператор перемещения
    Scoped_Thread& operator=(Scoped_Thread &&other) {
        t = std::move(other.t);
        return *this;
    }

    ~Scoped_Thread() {
        if (t.joinable()) t.join();
    };
};

void my_function() {
    double res;
    for (double d = 10; d < 2000000; d++)
        res = std::log10(d);

}
typedef void race_type();

void race_timing(race_type function, int number) {
    std::cout << "Race #" << number << " time is ";
    auto start_time = std::chrono::high_resolution_clock::now();
    function();
    auto finish_time = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>
                    (finish_time - start_time).count() << std::endl;

}

void race_1() {
    for (int i = 0; i < 300; i++) {
        Scoped_Thread t(std::move(std::thread(my_function)));
    };
}

void race_2() {
    for (int i = 0; i < 300; i++) {
        my_function();
    }
}

void race_3() {
    std::vector<std::thread*> threads;
    for (int i = 0; i < 300; i++) 
        threads.push_back(new std::thread(my_function));
    
    
    
    for (auto tt : threads) {
        tt->join();
        delete tt;
    }
}

void race_4() {
    std::vector<Scoped_Thread> threads;
    for (int i = 0; i < 300; i++) threads.push_back(
            std::move(
                  Scoped_Thread(
                     std::move(
                       std::thread(my_function)))));
}

void race_5(){
    int hc = std::thread::hardware_concurrency();
    std::vector<std::thread*> threads;
    for(int i=0;i<300/hc;i++)
    {
            
            for(int j=0;j<hc;j++)
                    threads.push_back(new std::thread(my_function));
            for (auto tt : threads) {
                    tt->join(); delete tt;
                    
            }
            threads.clear();
    }   
}

int main() {

    std::cout << "Hardware processes:" << std::thread::hardware_concurrency() << std::endl;


    race_timing(race_1, 1);
    race_timing(race_2, 2);
    race_timing(race_3, 3);
    race_timing(race_4, 4);
    race_timing(race_5, 5);

    return 0;
}
#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>

class Scoped_Thread
{
    std::thread t;

public:
    Scoped_Thread(std::thread &&t_) : t(std::move(t_))
    {
        if (!t.joinable())
            throw std::logic_error("No thread");
    };

    Scoped_Thread(std::thread &t_) : t(std::move(t_))
    {
        if (!t.joinable())
            throw std::logic_error("No thread");
    };

    // выглядит как конструктор копирования, а на самом деле - перемещения

    Scoped_Thread(Scoped_Thread &other) : t(std::move(other.t)){};
    Scoped_Thread(Scoped_Thread &&other) : t(std::move(other.t)){};
    // оператор перемещения
    Scoped_Thread &operator=(Scoped_Thread &&other)
    {
        t = std::move(other.t);
        return *this;
    }

    ~Scoped_Thread()
    {
        if (t.joinable())
            t.join();
    };
};

void add_function(long *number, std::mutex *lock)
{
    for (long i = 0; i < 1000000L; i++)
    {
        lock->lock();
        (*number)++;
        lock->unlock();
    }
}

void subst_function(long *number, std::mutex *lock)
{
    for (long i = 0; i < 1000000L; i++)
    {
        lock->lock();
        (*number)--;
        lock->unlock();
    }
}

void threadFunction(std::mutex *lock)
{
    try
    {
        std::cout << "waithing thread " << std::this_thread::get_id() << std::endl;
        lock->lock();
        std::cout << "entered thread " << std::this_thread::get_id() << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(rand() % 5));
        std::cout << "leaving thread " << std::this_thread::get_id() << std::endl;
        throw 0;
        lock->unlock();
    }
    catch (...)
    {
    }
}

int main(int argc, char *argv[])
{

    long number = 0;
    std::mutex lock;
    /*
    {
        Scoped_Thread th1(std::move(std::thread(add_function,&number,&lock)));
        Scoped_Thread th2(std::move(std::thread(subst_function,&number,&lock)));
    }
    
    std::cout << "Result:" << number << std::endl;
/*/
    srand((unsigned int)time(0));
    std::thread t1(threadFunction, &lock);
    std::thread t2(threadFunction, &lock);
    std::thread t3(threadFunction, &lock);
    t1.join();
    t2.join();
    t3.join();
    //*/

    return 0;
}
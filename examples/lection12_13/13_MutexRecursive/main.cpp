#include <iostream>
#include <thread>
#include <mutex>

template <class MUTEX> void threadFunction2(MUTEX *lock) {
    lock->lock();
    std::cout << "again entered thread " << std::this_thread::get_id() << std::endl;
    std::cout << "again leaving thread " << std::this_thread::get_id() << std::endl;
    lock->unlock();
}

template <class MUTEX> void threadFunction(MUTEX *lock) {
    lock->lock();
    std::cout << "entered thread " << std::this_thread::get_id() << std::endl;
    threadFunction2<MUTEX>(lock);
    std::cout << "leaving thread " << std::this_thread::get_id() << std::endl;

    lock->unlock();
}

int main(int argc, char * argv[]) {
//*
    std::recursive_mutex lock1;
    std::thread t1(threadFunction<std::recursive_mutex>, &lock1);
    t1.join();
    /*/
    std::cout << std::endl << "Never ending story ..." <<std::endl;
    
    std::mutex lock2;
    std::thread t2(threadFunction<std::mutex>, &lock2);
    t2.join();
    //*/
    return 0;
}
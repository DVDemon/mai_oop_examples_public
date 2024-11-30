#include <cstdlib>
#include <atomic>
#include <thread>
#include <vector>
#include <iostream>
#include <cassert>

using namespace std;

class spin_lock 
{
    atomic<unsigned int> m_spin ;
public:
    spin_lock(): m_spin(0) {}
    ~spin_lock() { assert( m_spin.load(memory_order_relaxed) == 0);}

    void lock()
    {
        unsigned int nCur;
        do { nCur = 0; } // устанавливаем "старое значение" в 0
        while ( !m_spin.compare_exchange_weak( nCur, 1, memory_order_acquire )); 
        // если значение m_spin == 0 то меняем m_spin на 1 и выходим из цикла
        // если значение m_spin == 1 то меняем nCur на 1 и идем на еще один цикл
    }
    void unlock()
    {
        m_spin.store( 0, memory_order_release );
    }
};


int main(int argc, char** argv) {

    std::vector<std::thread*> threads;
    int value{};
    spin_lock lck;
    
    for(int i=0;i<50000;i++) threads.push_back(new std::thread(
                [&value,&lck](){
                        lck.lock();
                        value++;
                        lck.unlock();
                    }));
    for(auto t:threads) t->join();
    std::cout<< value << std::endl;
    return 0;
}


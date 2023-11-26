#include <iostream>
#include <thread>


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

    Scoped_Thread(Scoped_Thread & other) : t(std::move(other.t)) {};
    Scoped_Thread(Scoped_Thread && other) : t(std::move(other.t)) {};
    // оператор перемещения
    Scoped_Thread& operator=(Scoped_Thread &&other) {
        t = std::move(other.t);
        return *this;
    }

    ~Scoped_Thread() {
        if (t.joinable()) t.join();
    };
};

void add_function( long * number){
    for( long i=0;i<1000000000L;i++) (*number)++;
}

void subst_function( long * number){
    for( long i=0;i<1000000000L;i++) (*number)--;
}

int main() {

    long number = 0;
    
    {
        Scoped_Thread th1(std::move(std::thread(add_function,&number)));
   // }{
        Scoped_Thread th2(std::move(std::thread(subst_function,&number)));
    }
    
    std::cout << "Result:" << number << std::endl;
    
    return 0;
}


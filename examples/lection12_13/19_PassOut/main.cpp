#include <iostream>
#include <thread>
#include <mutex>

class some_data
{
public:
	void do_something() const
	{
		std::cout << "Computatation" << std::endl;
	};
};

class data_wrapper
{
private:
        // защищенные данные, к которым ограничен доступ из разных потоков
	some_data data;
	std::mutex m;
public:
	template<typename Function>
	void process_data(Function func)
	{
		std::lock_guard<std::mutex> l(m);
		std::cout << "Start protected call" << std::endl;
		func(data); 
		std::cout << "End protected call" << std::endl;
	}
};

some_data* unprotected;

// Функция, которую хотим сделать потокобезопасной
void malicious_function(const some_data& protected_data)
{
	protected_data.do_something();
	unprotected = (some_data*)&protected_data;
}


int main()
{
	data_wrapper x;
        
	x.process_data<void (const some_data& protected_data)>(malicious_function);
	
	
	unprotected->do_something();
}
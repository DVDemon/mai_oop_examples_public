#include <iostream>
#include <thread>
#include <mutex>
#include <sstream>


std::mutex resource_A;
std::mutex resource_B;
std::timed_mutex resource_AT;
std::timed_mutex resource_BT;

struct print : std::stringstream{
    ~print(){
        static std::mutex mtx;
        std::lock_guard<std::mutex> lck(mtx);
        std::cout << this->str();
        std::cout.flush();
    }
};

void DeadLockA()
{
	std::lock_guard<std::mutex> lockA(resource_A);
	print() << "FooA: ResourceA locked" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	std::lock_guard<std::mutex> lockB(resource_B);
	print() << "FooA: ResourceB locked" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

void DeadLockB()
{
	std::lock_guard<std::mutex> lockB(resource_B);
	print() << "FooB: ResourceB locked" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	std::lock_guard<std::mutex> lockA(resource_A);
	print() << "FooB: ResourceA locked" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

void NotLockA()
{
	resource_AT.lock();
	print() << "A: ResourceAT locked" << std::endl;

	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	if (resource_BT.try_lock_for(std::chrono::milliseconds(2000)))
	{
		print() << "A: ResourceBT locked" << std::endl;
		resource_BT.unlock();
	}
	else print() << "A: Deadlock detected!!!!" << std::endl;
	resource_AT.unlock();
}

void NotLockB()
{
	resource_BT.lock();
	print() << "B: ResourceBT locked" << std::endl;

	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	if (resource_AT.try_lock_for(std::chrono::milliseconds(2000)))
	{
		print() << "B: ResourceAT locked" << std::endl;
		resource_AT.unlock();
	}
	else print() << "B: Deadlock detected!!!!" << std::endl;
	resource_BT.unlock();
}

int main(int argc, const char* argv[])
{
	print() << "Let's start:" << std::endl;

/*
	std::thread t1(DeadLockA);
	std::thread t2(DeadLockB);
	t1.join();
	t2.join();
/*/
	std::thread t1(NotLockA);
	std::thread t2(NotLockB);
	t1.join();
	t2.join();
//*/
	print() << "I don't belive in DeadLock" << std::endl;


	//std::cin.get();
}
#include <iostream>
#include <thread>
#include <mutex>
#include <shared_mutex>

std::shared_mutex mtx;
int shared_data = 0;

void read_data() {
    std::shared_lock<std::shared_mutex> lock(mtx);
    std::cout << "Reading data: " << shared_data << std::endl;
}

void write_data() {
    std::lock_guard<std::shared_mutex> lock(mtx);
    shared_data++;
    std::cout << "Writing data: " << shared_data << std::endl;
}

int main() {
    std::thread reader1(read_data);
    std::thread reader2(read_data);
    std::thread writer1(write_data);
    std::thread reader3(read_data);

    reader1.join();
    reader2.join();
    writer1.join();
    reader3.join();

    return 0;
}
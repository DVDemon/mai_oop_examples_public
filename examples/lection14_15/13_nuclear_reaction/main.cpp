// Fission / Nuclear reaction

#include <algorithm>
#include <atomic>
#include <iostream>
#include <functional>
#include <thread>
#include <vector>

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& values) {
    for (auto& v : values)
        os << v << ' ';
    return os;
}

void motivation() {
    std::cout << "\nmotivation\n";

    // std::vector<int> values(100500, 0);
    std::vector<int> values(10, 0);

    std::for_each(values.begin(), values.end(),
        [](int& value) {
            value += 42;
        }
    );
    std::cout << values << std::endl;
    std::cout << std::endl;
}

void nuclearReaction() {

    std::cout << "\nnuclearReaction\n";

    using Values_t = std::vector<int>;

    // Values_tvalues{100500, 0};
    Values_t values(100, 0);

    auto worker = [](const Values_t::iterator& from, const Values_t::iterator& to) {
        std::for_each(from, to,
            [](int& value) {
                value += 42;
            }
        );
    };

    int maxThreadCount = std::thread::hardware_concurrency();
    if (!maxThreadCount)
        maxThreadCount = 4;
    std::atomic<int> threadCount{1};

    std::function<void(const Values_t::iterator&, const Values_t::iterator&)> nuclearWorker;
    
    nuclearWorker = [&](
        const Values_t::iterator& from, 
        const Values_t::iterator& to
        ) {

            auto size = std::distance(from, to);
            std::cout << "Hello from thread [" << threadCount << "] with size = " << size << std::endl;

            if (threadCount > maxThreadCount || size < 10) {
                worker(from, to);
            }
            else {
                auto middle = std::next(from, size / 2);
                threadCount += 2;
                std::thread worker1 = std::thread(nuclearWorker, from, middle);
                std::thread worker2 = std::thread(nuclearWorker, middle, to);
                worker1.join();
                worker2.join();
            }
        };


    // Start nuclear reaction
    nuclearWorker(values.begin(), values.end());

    std::cout << values << std::endl;
    std::cout << std::endl;

}

int main() {
 //   motivation();
    nuclearReaction();

    return 0;
}
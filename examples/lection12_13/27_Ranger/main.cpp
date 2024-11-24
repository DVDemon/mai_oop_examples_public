#include <iostream>
#include <string>
#include <coroutine>
#include <list>
#include <optional>
#include <ctime>
#include <random>
#include <thread>
#include <chrono>
#include <map>
#include <cmath>

using namespace std::chrono_literals;

struct Stats {
    int x;
    int y;
    size_t id;
    int strength;
    bool alive;
};

struct Ranger{
    struct promise_type {
        std::optional<Stats> current_stats;
        Ranger get_return_object(){
            return Ranger {std::coroutine_handle<promise_type>::from_promise(*this)};
        }
        std::suspend_always initial_suspend() { return {}; }
        std::suspend_always final_suspend() noexcept { return {}; }
        void return_void() {}
        std::suspend_always yield_value(Stats stats) {
            current_stats = stats;
            return {};
        }
        void unhandled_exception() { std::terminate();}
    };

    std::coroutine_handle<promise_type> coro;
    
    explicit Ranger(std::coroutine_handle<promise_type> c) : coro(c) {}
    Ranger(Ranger&& other) noexcept : coro(other.coro) { other.coro = nullptr;}
    Ranger(const Ranger&) = delete;
    Ranger& operator=(const Ranger&) = delete;
    ~Ranger() {if(coro) coro.destroy();}

    // Получение следующего значения из корутины
    bool move_next() {
        coro.resume();
        return !coro.done();
    }

    Stats& get_stats() {
        return *(coro.promise().current_stats);
    }
};


Ranger ranger_action(size_t id, int min_x,int min_y,int max_x,int max_y) {

    Stats stats {std::rand()%(max_x-min_x)+min_x,
                 std::rand()%(max_y-min_y)+min_y,
                 id,
                 std::rand()%19,
                 true};

    while(stats.alive) {
        std::cout << "Ranger " << stats.id << " [" << stats.x << "," << stats.y << "] strength=" << stats.strength << " ";
        
        int distance = std::rand() % 20;
        switch(std::rand() % 4){
            case 0: // move left
                std::cout << "Moving left: ";
                while ((stats.x > min_x) && (distance > 0)) {
                    --stats.x;
                    --distance;
                    std::cout << "." << std::flush;
                    std::this_thread::sleep_for(100ms);
                }
                std::cout << std::endl;
                break;
            case 1: // move right
            std::cout << "Moving right: ";
                while ((stats.x < max_x) && (distance > 0)) {
                    ++stats.x;
                    --distance;
                    std::cout << "." << std::flush;
                    std::this_thread::sleep_for(100ms);
                }
                std::cout << std::endl;
                break;
            case 2: // move top
            std::cout << "Moving top: ";
                while ((stats.y > min_y) && (distance > 0)) {
                    --stats.y;
                    --distance;
                    std::cout << "." << std::flush;
                    std::this_thread::sleep_for(100ms);
                }
                std::cout << std::endl;
                break;
            case 3: // move bottom
            std::cout << "Moving bottom: ";
                while ((stats.y < max_y) && (distance > 0)) {
                    ++stats.y;
                    --distance;
                    std::cout << "." << std::flush;
                    std::this_thread::sleep_for(100ms);
                }
                std::cout << std::endl;
                break;
        }

        co_yield stats;
    }
}

auto main() -> int {
    std::srand(std::time(nullptr));
    const size_t distance = 10;
    int min_x = 0, max_x = 100;
    int min_y = 0, max_y = 100;

    std::list<Ranger> rangers;
    for(size_t i=0;i<10;++i)
        rangers.push_back(ranger_action(i,min_x,min_y,max_x,max_y));
    
    std::map<int,Stats> stats;
    while(true) {
        std::cout << "Moving phase:" << std::endl;
        size_t index {0};
        for(auto &r : rangers) {
            bool alive = true;
            if (stats.find(index)!=std::end(stats)) 
                alive = stats[index].alive;

            if(alive) {
                r.move_next();
                stats[index] = std::move(r.get_stats());
            }
            ++index;
        }
    
        std::cout  << std::endl;

        std::cout << "Fighting phase:" << std::endl;
        for(auto & [left_id,left] : stats)
            for(auto & [right_id,right] : stats)
                if(left.alive && right.alive)
                if(left_id!=right_id){
                    if( std::pow(left.x-right.x,2)+std::pow(left.y-right.y,2)<400) {// находятся вблизи
                        if (left.strength < right.strength) {
                            left.alive = false;
                            std::cout << "ranger " << left.id << " die" << std::endl;
                        }
                    }      
                }

        std::cout << "press enter" << std::endl;

        std::cin.get();
    }

    return 0;
}
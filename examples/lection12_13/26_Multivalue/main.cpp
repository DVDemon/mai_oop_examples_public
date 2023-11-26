#include <experimental/coroutine>
#include <iostream>
#include <exception>

struct Generator {
    struct promise_type {
        int current_value;
        int other_value;

        Generator get_return_object() {
            return Generator{std::experimental::coroutine_handle<promise_type>::from_promise(*this)};
        }
        std::experimental::suspend_always initial_suspend() { return {}; }
        std::experimental::suspend_always final_suspend() noexcept { return {}; }
        void unhandled_exception() {}

        std::experimental::suspend_always yield_value(std::pair<int, int> value) {
            current_value = value.first;
            other_value = value.second;
            return {};
        }
        void return_void(){};
    };

    std::experimental::coroutine_handle<promise_type> h;

    Generator(std::experimental::coroutine_handle<promise_type> h) : h(h) {}

    ~Generator() {
        if (h) {
            h.destroy();
        }
    }

    bool next() {
        std::cout << "do something ... " << std::endl;
        h.resume();
        return !h.done();
    }

    std::pair<int, int> getValue() {
        return {h.promise().current_value, h.promise().other_value};
    }
};

Generator sequence() {
    for (int i = 0; i < 10; ++i) {
        co_yield {i, i * 2};
    }
}

int main() {
    auto gen = sequence();
    while (gen.next()) {
        auto [yieldedValue, otherValue] = gen.getValue();
        std::cout << "Yielded value: " << yieldedValue << ", Other value: " << otherValue << std::endl;
    }
}
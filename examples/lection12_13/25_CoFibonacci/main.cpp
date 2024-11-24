#include <iostream>
#include <coroutine>
#include <optional>

// Класс, который будет использоваться для возврата значений из корутины
struct FibonacciGenerator {
    struct promise_type {
        std::optional<int> current_value;

        FibonacciGenerator get_return_object() {
            return FibonacciGenerator{std::coroutine_handle<promise_type>::from_promise(*this)};
        }

        std::suspend_always initial_suspend() { return {}; }
        std::suspend_always final_suspend() noexcept { return {}; }

        void return_void() {}

        std::suspend_always yield_value(int value) {
            current_value = value;
            return {};
        }

        void unhandled_exception() {
            std::terminate();
        }
    };

    std::coroutine_handle<promise_type> coro;

    explicit FibonacciGenerator(std::coroutine_handle<promise_type> coro) : coro(coro) {}

    ~FibonacciGenerator() {
        if (coro) coro.destroy();
    }

    // Перемещение корутины
    FibonacciGenerator(FibonacciGenerator&& other) noexcept : coro(other.coro) {
        other.coro = nullptr;
    }

    // Запрет копирования
    FibonacciGenerator(const FibonacciGenerator&) = delete;
    FibonacciGenerator& operator=(const FibonacciGenerator&) = delete;

    // Получение следующего значения из корутины
    bool move_next() {
        coro.resume();
        return !coro.done();
    }

    int current_value() {
        return *coro.promise().current_value;
    }
};

// Корутина, которая возвращает последовательность чисел Фибоначчи
FibonacciGenerator fibonacci() {
    int a = 0, b = 1;
    while (true) {
        co_yield b;
        int next = a + b;
        a = b;
        b = next;
    }
}

int main() {
    auto gen = fibonacci();

    for (int i = 0; i < 10; ++i) {
        gen.move_next();
        std::cout << gen.current_value() << std::endl;
    }

    return 0;
}
#include <iostream>
#include <coroutine>
#include <optional>

// Класс, который будет использоваться для возврата значений из корутины
// Этот класс представляет собой корутину, которая возвращает последовательность значений. 
// Он содержит promise_type, который определяет поведение корутины.

struct Generator {
    // Этот вложенный класс определяет, как корутина будет вести себя на разных этапах своего жизненного цикла
    struct promise_type {
        std::optional<int> current_value;

        // Возвращает объект Generator, который будет использоваться для взаимодействия с корутиной.
        Generator get_return_object() {
            return Generator{std::coroutine_handle<promise_type>::from_promise(*this)};
        }

        // initial_suspend и final_suspend: Определяют, когда корутина должна приостановиться в начале и в конце.
        std::suspend_always initial_suspend() { return {}; }
        std::suspend_always final_suspend() noexcept { return {}; }

        void return_void() {}

        // Определяет, как корутина будет возвращать значения.
        std::suspend_always yield_value(int value) {
            current_value = value;
            return {};
        }

        // Обрабатывает необработанные исключения.
        void unhandled_exception() {
            std::terminate();
        }
    };

    std::coroutine_handle<promise_type> coro;

    explicit Generator(std::coroutine_handle<promise_type> coro) : coro(coro) {}

    ~Generator() {
        if (coro) coro.destroy();
    }

    // Перемещение корутины
    Generator(Generator&& other) noexcept : coro(other.coro) {
        other.coro = nullptr;
    }

    // Запрет копирования
    Generator(const Generator&) = delete;
    Generator& operator=(const Generator&) = delete;

    // Получение следующего значения из корутины
    bool move_next() {
        coro.resume();
        return !coro.done();
    }

    int current_value() {
        return *coro.promise().current_value;
    }
};


// Это сама корутина, которая генерирует последовательность чисел от start до end. 
// Она использует co_yield для возврата значений.
Generator sequence(int start, int end) {
    for (int i = start; i <= end; ++i) {
        co_yield i;
    }
}

int main() {
    auto gen = sequence(1, 5);

// Метод move_next возобновляет выполнение корутины и возвращает true, если корутина еще не завершилась. 
// Метод current_value возвращает текущее значение, возвращенное корутиной.
    while (gen.move_next()) {
        std::cout << gen.current_value() << std::endl;
    }

    return 0;
}
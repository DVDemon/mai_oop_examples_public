#include <iostream>
#include <exception>
#include <string>

// Пользовательское исключение для обработки ошибок индексации массива
class BadIndexException : public std::exception
{
private:
    std::string error_message;  // Сообщение об ошибке

public:
    // Конструктор, создающий информативное сообщение об ошибке
    BadIndexException(int index, int size)
    {
        error_message = "Index:" + std::to_string(index) + 
                       " is out of bound for array[0.." + 
                       std::to_string(size - 1) + "]";
    }

    // Переопределение виртуальной функции what() для возврата сообщения об ошибке
    const char* what() const noexcept override
    {
        return error_message.c_str();
    }
};

// Шаблон класса Array с тремя параметрами:
// 1. TYPE - тип элементов массива
// 2. def_value - значение по умолчанию (должно быть того же типа, что и TYPE)
// 3. SIZE - размер массива (параметр по умолчанию = 10)
template <class TYPE, TYPE default_value, size_t SIZE = 10>
class Array
{
protected:
    TYPE array_data[SIZE];  // Массив фиксированного размера

public:
    // Конструктор, инициализирующий все элементы значением по умолчанию
    Array()
    {
        for (auto& element : array_data) {
            element = default_value;
        }
    }

    // Метод для получения размера массива
    const size_t size() const
    {
        return SIZE;
    }

    // Итераторы для поддержки range-based for
    TYPE* begin()
    {
        return &array_data[0];
    }

    TYPE* end()
    {
        return &array_data[SIZE];  // Элемент, следующий за концом массива
    }

    // Оператор доступа к элементам с проверкой границ
    TYPE& operator[](size_t index)
    {
        if ((index >= 0) && (index < SIZE)) {
            return array_data[index];
        } else {
            throw BadIndexException(index, SIZE);
        }
    }
};

int main()
{
    try {
        // Демонстрация сложных параметров шаблона:
        // Array<int, 0, my_size> означает:
        // - TYPE = int (тип элементов)
        // - default_value = 0 (значение по умолчанию)
        // - SIZE = my_size (размер массива)
        const int my_size = 10;
        Array<int, 0, my_size> array;

        // Инициализация массива значениями 0, 1, 2, ..., 9
        for (int i = 0; i < array.size(); i++) {
            array[i] = i;
        }

        // Вывод исходного массива
        std::cout << "Original array: ";
        for (auto element : array) {
            std::cout << element << " ";
        }
        std::cout << std::endl;

        // Возведение каждого элемента в квадрат (изменение по ссылке)
        for (auto& element : array) {
            element *= element;
        }

        // Вывод измененного массива
        std::cout << "Squared array: ";
        for (auto element : array) {
            std::cout << element << " ";
        }
        std::cout << std::endl;

        // Демонстрация обработки исключений - попытка доступа к несуществующему индексу
        std::cout << "Trying to access array[255]: ";
        std::cout << array[255] << std::endl;  // Это вызовет исключение

    } catch (const std::exception& exception) {
        // Обработка исключения с выводом информативного сообщения
        std::cout << "Exception in runtime" << std::endl;
        std::cout << exception.what() << std::endl;
    }

    return 0;
}


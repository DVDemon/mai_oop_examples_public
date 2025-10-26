#include <iostream>
#include <memory>
#include <initializer_list>

/**
 * Исключение для выхода за границы массива
 * Выбрасывается при попытке доступа к несуществующему элементу
 */
class OutOfBoundException {
};

/**
 * Пользовательский итератор для динамического массива
 * Реализует базовую функциональность итератора для работы с контейнерами
 * 
 * @tparam ItemType - тип элементов массива
 * @tparam ArrayType - тип массива (контейнера)
 */
template <class ArrayType>
class ArrayIterator {
private:
    ArrayType* array_pointer;  // Указатель на массив
    size_t current_index;      // Текущий индекс
    size_t array_size;         // Размер массива

public:
    /**
     * Конструктор итератора
     * @param array_pointer - указатель на массив
     * @param start_index - начальный индекс
     * @param array_size - размер массива
     */
    ArrayIterator(ArrayType* array_pointer, size_t start_index, size_t array_size) 
        : array_pointer(array_pointer), current_index(start_index), array_size(array_size) {
    }

    /**
     * Оператор разыменования - получение значения элемента
     * @return ссылка на элемент массива
     * @throws OutOfBoundException если индекс выходит за границы
     */
    typename ArrayType::item_type operator*() {
        if (current_index >= array_size) {
            throw OutOfBoundException();
        }
        return (*array_pointer)[current_index];
    }

    /**
     * Оператор доступа к членам - получение указателя на элемент
     * @return указатель на элемент массива
     * @throws OutOfBoundException если индекс выходит за границы
     */
     typename ArrayType::item_type operator->() {
        if (current_index >= array_size) {
            throw OutOfBoundException();
        }
        return (*array_pointer)[current_index];
    }

    /**
     * Оператор неравенства для сравнения итераторов
     * @param other - другой итератор для сравнения
     * @return true если итераторы указывают на разные позиции или массивы
     */
    bool operator!=(const ArrayIterator<ArrayType>& other) const {
        return (other.current_index != current_index) || (other.array_pointer != array_pointer);
    }

    /**
     * Префиксный оператор инкремента - переход к следующему элементу
     * @return ссылка на обновленный итератор
     */
    ArrayIterator<ArrayType>& operator++() {
        ++current_index;
        return *this;
    }
};

/**
 * Динамический массив с пользовательским итератором
 * Демонстрирует создание контейнера с поддержкой range-based for loop
 * 
 * @tparam T - тип элементов массива
 */
template <class T>
class DynamicArray {
private:
    std::unique_ptr<T[]> data_pointer;  // Умный указатель на данные
    const size_t array_size;            // Размер массива (константа)

public:

    using item_type = T;
    /**
     * Конструктор с заданным размером
     * @param array_size - размер создаваемого массива
     */
    explicit DynamicArray(size_t array_size) : array_size(array_size) {
        data_pointer.reset(new T[array_size]);
    }

    /**
     * Конструктор с инициализатором списка
     * @param initialization_list - список значений для инициализации
     */
    DynamicArray(std::initializer_list<T> initialization_list) 
        : array_size(initialization_list.size()), data_pointer(new T[initialization_list.size()]) {
        std::copy(initialization_list.begin(), initialization_list.end(), data_pointer.get());
    }

    /**
     * Оператор доступа к элементам по индексу
     * @param element_index - индекс элемента
     * @return ссылка на элемент массива
     * @throws OutOfBoundException если индекс выходит за границы
     */
    T& operator[](size_t element_index) {
        if (element_index >= array_size) {
            throw OutOfBoundException();
        }
        return data_pointer.get()[element_index];
    }

    /**
     * Получение итератора на начало массива
     * @return итератор, указывающий на первый элемент
     */
    ArrayIterator<DynamicArray<T>> begin() {
        return ArrayIterator<DynamicArray<T>>(this, 0, array_size);
    }

    /**
     * Получение итератора на конец массива
     * @return итератор, указывающий за последний элемент
     */
    ArrayIterator<DynamicArray<T>> end() {
        return ArrayIterator<DynamicArray<T>>(this, array_size, array_size);
    }
};

/**
 * Основная функция - демонстрация пользовательского итератора
 * Показывает различные способы итерации по динамическому массиву
 */
int main(int argc, char** argv) {
    std::cout << "=== ДЕМОНСТРАЦИЯ ПОЛЬЗОВАТЕЛЬСКОГО ИТЕРАТОРА ===" << std::endl;

    // ========================================================================
    // СОЗДАНИЕ И ИНИЦИАЛИЗАЦИЯ ДИНАМИЧЕСКОГО МАССИВА
    // ========================================================================
    DynamicArray<int> dynamic_array(10);

    // Заполнение массива значениями
    dynamic_array[0] = 10;
    dynamic_array[1] = 8;
    dynamic_array[2] = 9;

    // ========================================================================
    // ДЕМОНСТРАЦИЯ 1: РАБОТА С ИТЕРАТОРОМ ВРУЧНУЮ
    // ========================================================================
    std::cout << "1. Работа с итератором вручную:" << std::endl;
    auto manual_iterator = dynamic_array.begin();
    ++manual_iterator;
    // std::next(manual_iterator, 3);  // Альтернативный способ перемещения
    // manual_iterator += 3;            // Еще один способ (если реализован)
    std::cout << "Значение через итератор: " << *manual_iterator << std::endl;

    // ========================================================================
    // ДЕМОНСТРАЦИЯ 2: КЛАССИЧЕСКИЙ ЦИКЛ С ИТЕРАТОРАМИ
    // ========================================================================
    std::cout << "2. Классический цикл с итераторами:" << std::endl;
    for (ArrayIterator<DynamicArray<int>> iterator = dynamic_array.begin(); 
         iterator != dynamic_array.end(); ++iterator) {
        std::cout << *iterator << " ";
    }
    std::cout << std::endl;

    // ========================================================================
    // ДЕМОНСТРАЦИЯ 3: ИСПОЛЬЗОВАНИЕ STD::BEGIN/END
    // ========================================================================
    std::cout << "3. Использование std::begin/std::end:" << std::endl;
    for (auto iterator = std::begin(dynamic_array); iterator != std::end(dynamic_array); ++iterator) {
        std::cout << *iterator << " ";
    }
    std::cout << std::endl;

    // ========================================================================
    // ДЕМОНСТРАЦИЯ 4: RANGE-BASED FOR LOOP
    // ========================================================================
    std::cout << "4. Range-based for loop:" << std::endl;
    for (auto element : dynamic_array) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // ========================================================================
    // ДЕМОНСТРАЦИЯ 5: ИНИЦИАЛИЗАЦИЯ СПИСКОМ И RANGE-BASED FOR
    // ========================================================================
    std::cout << "5. Инициализация списком и range-based for:" << std::endl;
    DynamicArray<int> initialized_array{1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto element : initialized_array) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    std::cout << "\n=== ДЕМОНСТРАЦИЯ ЗАВЕРШЕНА ===" << std::endl;
    return 0;
}

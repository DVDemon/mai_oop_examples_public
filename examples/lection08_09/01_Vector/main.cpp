#include <iostream>
#include <vector>

/**
 * Демонстрация размещения объектов в памяти
 * Вектор располагается на стеке, а данные вектора - в куче
 */
void testMemoryPlacement() {
    std::cout << "\n=== ТЕСТ РАЗМЕЩЕНИЯ В ПАМЯТИ ===" << std::endl;

    int stack_variable = 0;
    std::vector<int> vector_data = {0, 1, 2, 3};

    std::cout << "Адрес переменной на стеке: " << &stack_variable << std::endl;
    std::cout << "Адрес объекта vector:     " << &vector_data << std::endl;
    std::cout << "Адрес данных vector:      " << vector_data.data() << std::endl;

    // Демонстрация range-based for loop
    std::cout << "Элементы vector (range-based for): ";
    for (const auto& element : vector_data) {
        std::cout << element << ' ';
    }
    std::cout << std::endl;

    // Демонстрация итераторов
    std::cout << "Элементы vector (итераторы): ";
    for (auto iterator = vector_data.begin(); iterator != vector_data.end(); ++iterator) {
        std::cout << *iterator << ' ';
    }
    std::cout << std::endl;

    // Демонстрация работы с обычными массивами
    int array_data[] = {1, 2, 3, 4, 5};
    std::cout << "Элементы массива (std::begin/end): ";
    for (auto iterator = std::begin(array_data); iterator != std::end(array_data); ++iterator) {
        std::cout << *iterator << ' ';
    }
    std::cout << std::endl;

    int another_array[5] = {1, 2, 3, 4, 5};
    std::cout << "Элементы массива (range-based for): ";
    for (auto& element : another_array) {
        std::cout << element << ' ';
    }
    std::cout << std::endl;
}

/**
 * Демонстрация стратегии перераспределения памяти в vector
 * Показывает, как vector увеличивает свою емкость при добавлении элементов
 */
void testMemoryReallocation() {
    std::cout << "\n=== ТЕСТ ПЕРЕРАСПРЕДЕЛЕНИЯ ПАМЯТИ ===" << std::endl;

    std::vector<int> dynamic_vector;
    auto previous_capacity = dynamic_vector.capacity();
    
    std::cout << "[" << 0 << "] Емкость = " << dynamic_vector.capacity() << std::endl;
    
    for (int element_index = 0; element_index < 10000; ++element_index) {
        if (previous_capacity != dynamic_vector.capacity()) {
            std::cout << "[" << element_index << "] Емкость = " << dynamic_vector.capacity() << std::endl;
            previous_capacity = dynamic_vector.capacity();
        }
        dynamic_vector.push_back(element_index);
    }
    std::cout << std::endl;
}

/**
 * Демонстрация методов reserve() и shrink_to_fit()
 * Показывает, как можно управлять емкостью vector
 */
void testCapacityManagement() {
    std::cout << "\n=== ТЕСТ УПРАВЛЕНИЯ ЕМКОСТЬЮ ===" << std::endl;

    const int total_elements = 100;
    std::vector<int> managed_vector;

    // Резервируем место заранее
    managed_vector.reserve(total_elements);
    std::cout << "Емкость после reserve(" << total_elements << "): " << managed_vector.capacity() << std::endl;

    // Добавляем половину элементов
    for (int element_index = 0; element_index < total_elements / 2; ++element_index) {
        managed_vector.push_back(element_index);
    }

    std::cout << "Емкость после добавления " << total_elements / 2 << " элементов: " << managed_vector.capacity() << std::endl;

    // Сжимаем до фактического размера
    std::cout << "Выполняем shrink_to_fit()..." << std::endl;
    managed_vector.shrink_to_fit();

    std::cout << "Емкость после shrink_to_fit(): " << managed_vector.capacity() << std::endl;
    
    // Добавляем еще один элемент
    std::cout << "Добавляем еще один элемент..." << std::endl;
    managed_vector.push_back(42);

    std::cout << "Емкость после добавления элемента: " << managed_vector.capacity() << std::endl;
}

/**
 * Демонстрация работы с итераторами vector
 * Показывает различные операции с итераторами и их инвалидацию
 */
void testIteratorOperations() {
    std::cout << "\n=== ТЕСТ ОПЕРАЦИЙ С ИТЕРАТОРАМИ ===" << std::endl;

    std::vector<int> iterator_vector = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    iterator_vector.reserve(20);
    std::cout << "Емкость vector: " << iterator_vector.capacity() << std::endl;

    // Получение первого элемента через итератор
    std::cout << "Первый элемент: " << *iterator_vector.begin() << std::endl;

    // Создание итератора на 4-й элемент (индекс 3)
    auto current_iterator = std::next(iterator_vector.cbegin(), 3);
    std::cout << "Элемент на позиции 3: " << *current_iterator << std::endl;

    // Перемещение итератора вперед
    ++current_iterator;
    std::cout << "Следующий элемент: " << *current_iterator << std::endl;

    // Перемещение итератора назад
    --current_iterator;
    --current_iterator;
    std::cout << "Предыдущий элемент: " << *current_iterator << std::endl;

    // Перемещение итератора на 3 позиции вперед
    current_iterator += 3;
    std::cout << "Элемент через 3 позиции: " << *current_iterator << std::endl;

    // Вычисление позиции итератора
    auto iterator_position = std::distance(iterator_vector.cbegin(), current_iterator);
    std::cout << "Позиция итератора: " << iterator_position << std::endl;

    // Добавление элемента в конец
    std::cout << "Добавляем элемент в конец..." << std::endl;
    iterator_vector.push_back(42);
    std::cout << "Емкость после push_back: " << iterator_vector.capacity() << std::endl;

    // Проверка адресов элементов
    std::cout << "Адрес первого элемента: " << &iterator_vector[0] << std::endl;
    std::cout << "Адрес элемента на позиции " << iterator_position << ": " << &iterator_vector[iterator_position] << std::endl;
    
    // Сжатие vector - итераторы становятся невалидными!
    iterator_vector.shrink_to_fit();
    std::cout << "ВНИМАНИЕ: После shrink_to_fit() итераторы могут стать невалидными!" << std::endl;
    std::cout << "Адрес через итератор: " << &*current_iterator << std::endl;

    // Создание нового итератора
    auto new_iterator = std::next(iterator_vector.cbegin(), 3);
    std::cout << "Новый итератор на позиции 3: " << *new_iterator << std::endl;
    
    // Вставка элемента в начало - все итераторы становятся невалидными!
    std::cout << "Вставляем элемент в начало..." << std::endl;
    iterator_vector.insert(iterator_vector.cbegin(), 42);

    std::cout << "ВНИМАНИЕ: После insert() в начало все итераторы невалидны!" << std::endl;
    std::cout << "Попытка использовать невалидный итератор: " << *new_iterator << std::endl;
    new_iterator += 6;
    std::cout << "Еще одна попытка: " << *new_iterator << std::endl;
}


/**
 * Тестовая структура для демонстрации семантики копирования и перемещения
 * Содержит логирование всех операций для отслеживания вызовов
 */
struct TestStructure {
    // Конструктор с параметром
    explicit TestStructure(int initial_value) : m_value{initial_value} {
    }

    // Конструктор копирования
    TestStructure(const TestStructure& other) 
        : m_value{other.m_value} {
        std::cout << '[' << m_value << "] Вызов конструктора копирования!" << std::endl;
    }

    // Конструктор перемещения
    TestStructure(TestStructure&& other) noexcept
        : m_value{other.m_value} {
        std::cout << '[' << m_value << "] Вызов конструктора перемещения!" << std::endl;
    }

    // Оператор присваивания перемещения
    TestStructure& operator=(TestStructure&& other) noexcept {
        m_value = other.m_value;
        other.m_value = 0;
        std::cout << '[' << m_value << "] Вызов оператора присваивания перемещения!" << std::endl;
        return *this;
    }

    // Оператор присваивания копирования
    TestStructure& operator=(const TestStructure& other) {
        m_value = other.m_value;
        std::cout << '[' << m_value << "] Вызов оператора присваивания копирования!" << std::endl;
        return *this;
    }

private:
    int m_value;  // Значение структуры
};

/**
 * Демонстрация перераспределения памяти с пользовательскими объектами
 * Показывает, как vector перераспределяет память при добавлении объектов
 */
void testCustomObjectReallocation() {
    std::cout << "\n=== ТЕСТ ПЕРЕРАСПРЕДЕЛЕНИЯ С ПОЛЬЗОВАТЕЛЬСКИМИ ОБЪЕКТАМИ ===" << std::endl;
    std::vector<TestStructure> custom_objects;

    for (int object_index = 0; object_index < 5; ++object_index) {
        std::cout << "Емкость перед добавлением элемента " << object_index << ": " << custom_objects.capacity() << std::endl;
        
        // Демонстрация различных способов добавления элементов:
        
        // Способ 1: Создание временного объекта (много копирований)
        // TestStructure temporary_object{object_index};
        // custom_objects.push_back(temporary_object);
        
        // Способ 2: Создание временного объекта inline (копирование)
        // custom_objects.push_back(TestStructure(object_index));
        
        // Способ 3: Эффективное создание объекта на месте (рекомендуется)
        custom_objects.emplace_back(object_index);
    }
}

/**
 * Основная функция - демонстрация различных аспектов работы с std::vector
 */
int main() {
    std::cout << "=== ДЕМОНСТРАЦИЯ STD::VECTOR ===" << std::endl;

    // Тест 1: Размещение объектов в памяти
    testMemoryPlacement();
    
    // Тест 2: Стратегия перераспределения памяти
    testMemoryReallocation();
    
    // Тест 3: Управление емкостью vector
    testCapacityManagement();
    
    // Тест 4: Операции с итераторами
    testIteratorOperations();
    
    // Тест 5: Перераспределение с пользовательскими объектами
    testCustomObjectReallocation();

    return 0;
}
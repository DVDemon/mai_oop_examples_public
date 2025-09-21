#include "dasharray.h"

// === РЕАЛИЗАЦИЯ КОНСТРУКТОРОВ ===

// Конструктор по умолчанию
DashArray::DashArray() : arraySize(0), dataArray(nullptr) {
    std::cout << "Конструктор по умолчанию" << std::endl;
}

// Конструктор с заполнением
DashArray::DashArray(const size_t& arraySize, unsigned char defaultValue) {
    std::cout << "Конструктор с заполнением" << std::endl;
    this->arraySize = arraySize;
    this->dataArray = new unsigned char[arraySize];
    
    // Заполняем массив значением по умолчанию
    for (size_t i = 0; i < arraySize; ++i) {
        this->dataArray[i] = defaultValue;
    }
}

// Конструктор из списка инициализации (C++11)
DashArray::DashArray(const std::initializer_list<unsigned char>& initialValues) {
    std::cout << "Конструктор из списка инициализации" << std::endl;
    arraySize = initialValues.size();
    dataArray = new unsigned char[arraySize];
    
    // Копируем значения из списка инициализации
    size_t index = 0;
    for (const auto& value : initialValues) {
        dataArray[index++] = value;
    }
}

// Конструктор из строки
DashArray::DashArray(const std::string& sourceString) {
    std::cout << "Конструктор из строки" << std::endl;
    arraySize = sourceString.size();
    dataArray = new unsigned char[arraySize];
    
    // Копируем символы из строки
    for (size_t i = 0; i < arraySize; ++i) {
        dataArray[i] = static_cast<unsigned char>(sourceString[i]);
    }
}

// Копирующий конструктор (глубокое копирование)
DashArray::DashArray(const DashArray& other) {
    std::cout << "Копирующий конструктор" << std::endl;
    arraySize = other.arraySize;
    dataArray = new unsigned char[arraySize];
    
    // Глубокое копирование данных
    for (size_t i = 0; i < arraySize; ++i) {
        dataArray[i] = other.dataArray[i];
    }
}

// Перемещающий конструктор (C++11) - "крадет" ресурсы
DashArray::DashArray(DashArray&& other) noexcept {
    std::cout << "Перемещающий конструктор" << std::endl;
    
    // "Крадем" ресурсы у другого объекта
    arraySize = other.arraySize;
    dataArray = other.dataArray;
    
    // Обнуляем другой объект, чтобы деструктор не освободил память
    other.arraySize = 0;
    other.dataArray = nullptr;
}

// === РЕАЛИЗАЦИЯ ОПЕРАЦИЙ ===

// Сложение массивов (создает новый массив)
DashArray DashArray::add(const DashArray& other) {
    // Создаем новый массив с размером, равным сумме размеров
    return DashArray(this->arraySize + other.arraySize, '1');
}

// Вычитание массивов (может выбрасывать исключение)
DashArray DashArray::remove(const DashArray& other) {
    // Проверяем, можно ли вычесть (размер не может стать отрицательным)
    if (arraySize < other.arraySize) {
        throw std::logic_error("Размер массива не может быть отрицательным");
    }
    
    // Уменьшаем размер
    arraySize -= other.arraySize;
    
    // Возвращаем ссылку на текущий объект
    return *this;
}

// Сравнение массивов по размеру
bool DashArray::equals(const DashArray& other) const {
    return arraySize == other.arraySize;
}

// Вывод массива в поток
std::ostream& DashArray::print(std::ostream& outputStream) {
    for (size_t i = 0; i < arraySize; ++i) {
        outputStream << dataArray[i];
    }
    return outputStream;
}

// === РЕАЛИЗАЦИЯ ДЕСТРУКТОРА ===

// Деструктор - освобождает динамическую память
DashArray::~DashArray() noexcept {
    std::cout << "Деструктор" << std::endl;
    
    // Освобождаем память, если она была выделена
    if (dataArray != nullptr) {
        delete[] dataArray;
        dataArray = nullptr;
    }
    
    // Обнуляем размер для безопасности
    arraySize = 0;
}
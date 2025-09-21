#pragma once

#include <string>
#include <iostream>

// Класс DashArray - демонстрация управления динамической памятью
// Показывает различные конструкторы, включая перемещающий конструктор (C++11)
// Демонстрирует Правило пяти (Rule of Five) для управления ресурсами

class DashArray {
public:
    // === КОНСТРУКТОРЫ ===
    
    // Конструктор по умолчанию
    DashArray();
    
    // Конструктор с заполнением (размер + значение по умолчанию)
    DashArray(const size_t& arraySize, unsigned char defaultValue = 0);
    
    // Конструктор из списка инициализации (C++11)
    DashArray(const std::initializer_list<unsigned char>& initialValues);
    
    // Конструктор из строки
    DashArray(const std::string& sourceString);
    
    // === КОПИРУЮЩИЕ И ПЕРЕМЕЩАЮЩИЕ ОПЕРАЦИИ ===
    
    // Копирующий конструктор (Правило пяти)
    DashArray(const DashArray& other);
    
    // Перемещающий конструктор (C++11) - Правило пяти
    DashArray(DashArray&& other) noexcept;

    // === ОПЕРАЦИИ С МАССИВАМИ ===
    
    // Сложение массивов (создает новый массив)
    DashArray add(const DashArray& other);
    
    // Вычитание массивов (может выбрасывать исключение)
    DashArray remove(const DashArray& other);
    
    // Сравнение массивов по размеру
    bool equals(const DashArray& other) const;
    
    // Вывод массива в поток
    std::ostream& print(std::ostream& outputStream);

    // === ДЕСТРУКТОР ===
    
    // Виртуальный деструктор (Правило пяти)
    virtual ~DashArray() noexcept;

private:
    // === ДАННЫЕ-ЧЛЕНЫ ===
    
    size_t arraySize;           // Размер массива
    unsigned char* dataArray;   // Указатель на динамический массив
};

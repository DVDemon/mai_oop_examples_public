#ifndef SCORES_H
#define SCORES_H

#include <string>
#include <iostream>

// Класс Scores (Оценки) - демонстрирует перегрузку оператора [] для коллекций
// с const и не-const версиями для работы с константными объектами
class Scores {
public:
    // Удаленный конструктор по умолчанию - принудительное указание имени курса
    Scores() = delete;
    
    // Конструктор с параметром - использует список инициализации
    Scores(const std::string& course_name)
        : m_course_name{course_name} {
    }

    // ПЕРЕГРУЗКА ОПЕРАТОРА [] для ЧТЕНИЯ И ЗАПИСИ (не-const версия)
    // Возвращает ссылку для возможности изменения элементов коллекции
    double& operator[](size_t index);
    
    // ПЕРЕГРУЗКА ОПЕРАТОРА [] для ТОЛЬКО ЧТЕНИЯ (const версия)
    // Возвращает значение для работы с константными объектами
    double operator[](size_t index) const;

    // ПРИМЕР ЗАКОММЕНТИРОВАННОГО КОДА - inline реализации:
    /*
    double& operator[](size_t index) {
        assert((index >= 0) && (index < 20));
        return m_scores[index];
    }

    double operator[](size_t index) const {
        assert((index >= 0) && (index < 20));
        return m_scores[index];
    }
    */

    // Метод для вывода информации об оценках
    void print_info() const {
        std::cout << m_course_name << " : [ ";
        for (size_t i{}; i < 20; ++i) {
            std::cout << m_scores[i] << " ";
        }
        std::cout << "]" << std::endl;
    }

private:
    // Приватные поля класса
    std::string m_course_name;  // Название курса
    double m_scores[20]{};      // Массив оценок (20 элементов)
};

#endif // SCORES_H
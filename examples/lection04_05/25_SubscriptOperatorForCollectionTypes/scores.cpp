#include "scores.h"
#include <cassert>

// РЕАЛИЗАЦИЯ ПЕРЕГРУЖЕННОГО ОПЕРАТОРА [] для ЧТЕНИЯ И ЗАПИСИ
// Не-const версия - возвращает ссылку для изменения элементов
double& Scores::operator[](size_t index) {
    // ASSERT для проверки корректности индекса
    // ВАЖНО: проверяем границы массива (0 <= index < 20)
    assert((index >= 0) && (index < 20));
    
    // Вывод для демонстрации вызова не-const версии
    std::cout << "Calling non-const operator[] (reference version)" << std::endl;
    
    // Возвращаем ССЫЛКУ на элемент массива для возможности изменения
    return m_scores[index];
}

// РЕАЛИЗАЦИЯ ПЕРЕГРУЖЕННОГО ОПЕРАТОРА [] для ТОЛЬКО ЧТЕНИЯ
// Const версия - возвращает значение для работы с константными объектами
double Scores::operator[](size_t index) const {
    // ASSERT для проверки корректности индекса
    // ВАЖНО: проверяем границы массива (0 <= index < 20)
    assert((index >= 0) && (index < 20));
    
    // Вывод для демонстрации вызова const версии
    std::cout << "Calling const operator[] (value version)" << std::endl;
    
    // Возвращаем ЗНАЧЕНИЕ элемента массива (копию)
    return m_scores[index];
}
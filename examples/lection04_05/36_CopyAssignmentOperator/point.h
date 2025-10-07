#ifndef POINT_H
#define POINT_H
#include <iostream>

class Point
{
    // Дружественная функция вывода в поток
    friend std::ostream& operator<<(std::ostream& os, const Point& point);

public:
    // Конструктор по умолчанию
    // ВАЖНО: Инициализируем p_data как nullptr для безопасности
    Point() : p_data(nullptr) {}
    
    // Конструктор с параметрами для инициализации координат и данных
    // ВАЖНО: Выделяем память для p_data в куче
    Point(double x, double y, int data) : 
        m_x(x), m_y(y), p_data(new int(data))
    {
    }

	Point(const Point& point)
	{
		std::cout << "Copy constructor called to copy point " << point << std::endl;
		
		// Проверка на самокопирование (обычно не происходит в конструкторе)
		if (this != &point) {
			// В конструкторе копирования p_data еще не инициализирован,
			// поэтому НЕ вызываем delete
			p_data = new int(*(point.p_data));       // Выделяем новую память и копируем данные
			m_x = point.m_x;                         // Копируем координату x
			m_y = point.m_y;                         // Копируем координату y
		}
	}
    

    // Оператор присваивания копированием (Copy Assignment Operator)
    // ВАЖНО: Возвращает ссылку на *this для поддержки цепочки присваиваний
    Point& operator=(const Point& right_operand)
    {
        std::cout << "Copy assignment operator called" << std::endl;
        
        // Проверка на самоприсваивание (a = a)
        if (this != &right_operand) {
            delete p_data;                                    // Освобождаем старую память
            p_data = new int(*(right_operand.p_data));        // Выделяем новую память и копируем данные
            m_x = right_operand.m_x;                          // Копируем координату x
            m_y = right_operand.m_y;                          // Копируем координату y
        }
        return *this;  // Возвращаем ссылку на текущий объект
    }


    // Оператор присваивания перемещением (Move Assignment Operator)
    // ВАЖНО: noexcept указывает, что операция не выбрасывает исключений
    // Параметр НЕ const, так как мы изменяем right_operand
    Point& operator=(Point&& right_operand) noexcept
    {
        std::cout << "Move assignment operator called" << std::endl;
        
        // Проверка на самоприсваивание (a = std::move(a))
        if (this != &right_operand) {
            delete p_data;                    // Освобождаем старую память
            p_data = right_operand.p_data;    // Перехватываем указатель (перемещение)
            m_x = right_operand.m_x;          // Копируем координату x
            m_y = right_operand.m_y;          // Копируем координату y
            right_operand.p_data = nullptr;   // Обнуляем указатель в источнике
        }
        return *this;  // Возвращаем ссылку на текущий объект
    }

    // Метод для изменения данных
    void set_data(int data)
    {
        *p_data = data;
    }

    // Деструктор - освобождаем динамически выделенную память
    ~Point()
    {
        delete p_data;  // delete безопасен для nullptr
    }

private:
    // Метод для вычисления расстояния от начала координат (0,0) до точки
    double length() const;

private:
    double m_x{};      // Координата x точки
    double m_y{};      // Координата y точки
    int* p_data;       // Указатель на данные в куче
};

// Inline реализация оператора вывода в поток
inline std::ostream& operator<<(std::ostream& os, const Point& point)
{
    os << "Point [ x : " << point.m_x << ", y : " << point.m_y 
       << " data : " << *(point.p_data) << "]";
    return os;
}

#endif // POINT_H

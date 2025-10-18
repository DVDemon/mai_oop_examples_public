#ifndef BOX_CONTAINER_H
#define BOX_CONTAINER_H

#include <iostream>
#include <concepts>

// ============================================================================
// КОНТЕЙНЕР С ИСПОЛЬЗОВАНИЕМ ВСТРОЕННЫХ КОНЦЕПЦИЙ C++20
// ============================================================================

// Класс-шаблон контейнера с ограничениями на тип T
// Требует, чтобы тип T был конструируемым по умолчанию
template <typename T>
requires std::is_default_constructible_v<T>
class BoxContainer
{		
	// Константы для управления памятью
	static const size_t DEFAULT_CAPACITY = 5;  
	static const size_t EXPAND_STEPS = 5;
	
public:
	// ========================================================================
	// КОНСТРУКТОРЫ И ДЕСТРУКТОР
	// ========================================================================
	
	// Конструктор по умолчанию с заданной вместимостью
	BoxContainer(size_t capacity = DEFAULT_CAPACITY);
	
	// Конструктор копирования (требует, чтобы T был копируемым)
	BoxContainer(const BoxContainer& source) requires std::copyable<T>;
	
	// Деструктор
	~BoxContainer();
	
	// ========================================================================
	// ОПЕРАТОР ВЫВОДА
	// ========================================================================
	
	// Дружественная функция для вывода содержимого контейнера
	friend std::ostream& operator<<(std::ostream& output_stream, const BoxContainer<T>& container)
	{
		output_stream << "BoxContainer : [ size :  " << container.m_size
			<< ", capacity : " << container.m_capacity << ", items : " ;
				
		for(size_t index{0}; index < container.m_size; ++index){
			output_stream << container.m_items[index] << " " ;
		}
		output_stream << "]";
		
		return output_stream;
	}

	// ========================================================================
	// МЕТОДЫ ДОСТУПА К ДАННЫМ
	// ========================================================================
	
	// Получение текущего размера контейнера
	size_t size( ) const { return m_size; }
	
	// Получение текущей вместимости контейнера
	size_t capacity() const{return m_capacity;};
	
	// Получение элемента по индексу
	T get_item(size_t index) const{
		return m_items[index];
	}
	
	// ========================================================================
	// МЕТОДЫ УПРАВЛЕНИЯ ЭЛЕМЕНТАМИ
	// ========================================================================
	
	// Добавление элемента в контейнер
	void add(const T& item);
	
	// Удаление одного элемента
	bool remove_item(const T& item);
	
	// Удаление всех вхождений элемента
	size_t remove_all(const T& item);
	
	// ========================================================================
	// ОПЕРАТОРЫ
	// ========================================================================
	
	// Оператор += для добавления элементов из другого контейнера
	void operator +=(const BoxContainer<T>& operand);
	
	// Оператор присваивания
	void operator =(const BoxContainer<T>& source);
	
private : 
	// ========================================================================
	// ВСПОМОГАТЕЛЬНЫЕ МЕТОДЫ
	// ========================================================================
	
	// Расширение вместимости контейнера
	void expand(size_t new_capacity);	
	
private : 
	// ========================================================================
	// ЧЛЕНЫ ДАННЫХ
	// ========================================================================
	
	T * m_items;        // Указатель на массив элементов
	size_t m_capacity;  // Текущая вместимость
	size_t m_size;      // Текущий размер
};

// ============================================================================
// ВНЕШНИЕ ОПЕРАТОРЫ
// ============================================================================

// Оператор + для объединения двух контейнеров
template <typename T> requires std::is_default_constructible_v<T>
BoxContainer<T> operator +(const BoxContainer<T>& left, const BoxContainer<T>& right);

// ============================================================================
// РЕАЛИЗАЦИЯ МЕТОДОВ КЛАССА
// ============================================================================

// ========================================================================
// КОНСТРУКТОРЫ И ДЕСТРУКТОР
// ========================================================================

// Конструктор по умолчанию
template <typename T> requires std::is_default_constructible_v<T>
BoxContainer<T>::BoxContainer(size_t capacity)
{
	m_items = new T[capacity];
	m_capacity = capacity;
	m_size = 0;
}

// Конструктор копирования
template <typename T> requires std::is_default_constructible_v<T>
BoxContainer<T>::BoxContainer(const BoxContainer<T>& source) requires std::copyable<T>
{
	// Настройка нового контейнера
	m_items = new T[source.m_capacity];
	m_capacity = source.m_capacity;
	m_size = source.m_size;
	
	// Копирование элементов из источника
	for(size_t index{} ; index < source.size(); ++index){
		m_items[index] = source.m_items[index];
	}
}

// Деструктор
template <typename T> requires std::is_default_constructible_v<T>
BoxContainer<T>::~BoxContainer()
{
	delete[] m_items;
}


// ========================================================================
// ВСПОМОГАТЕЛЬНЫЕ МЕТОДЫ
// ========================================================================

// Расширение вместимости контейнера
template <typename T> requires std::is_default_constructible_v<T>
void BoxContainer<T>::expand(size_t new_capacity){
	std::cout << "Expanding to " << new_capacity << std::endl;
	T *new_items_container;

	if (new_capacity <= m_capacity)
		return; // Нужная вместимость уже есть
	
	// Выделение новой (большей) памяти
	new_items_container = new T[new_capacity];

	// Копирование элементов из старого массива в новый
	for(size_t index{} ; index < m_size; ++index){
		new_items_container[index] = m_items[index];
	}
	
	// Освобождение старого массива
	delete [ ] m_items;
	
	// Привязка текущего контейнера к новому массиву
	m_items = new_items_container;
	
	// Использование новой вместимости
	m_capacity = new_capacity;
}

// ========================================================================
// МЕТОДЫ УПРАВЛЕНИЯ ЭЛЕМЕНТАМИ
// ========================================================================

// Добавление элемента в контейнер
template <typename T> requires std::is_default_constructible_v<T>
void BoxContainer<T>::add(const T& item){
	if (m_size == m_capacity)
		// Расширение с шагом EXPAND_STEPS для оптимизации вызовов expand
		expand(m_size + EXPAND_STEPS);
	m_items[m_size] = item;
	++m_size;
}


// Удаление одного элемента
template <typename T> requires std::is_default_constructible_v<T>
bool BoxContainer<T>::remove_item(const T& item){
	
	// Поиск целевого элемента
	size_t target_index {m_capacity + 999}; // Большое значение вне диапазона текущего массива
	for(size_t index{0}; index < m_size ; ++index){
		if (m_items[index] == item){
			target_index = index;
			break; // Нет необходимости продолжать цикл
		}
	}
	
	if(target_index > m_size)
		return false; // Элемент не найден в контейнере
		
	// Если мы дошли сюда, элемент находится в m_items[target_index]
	
	// Замена элемента по индексу последним элементом и уменьшение m_size
	m_items[target_index] = m_items[m_size-1];
	m_size--;
	return true;
}

// Удаление всех вхождений элемента
// Удаление всех - это удаление одного элемента несколько раз,
// пока не останется ни одного, с подсчетом удаленных элементов
template <typename T> requires std::is_default_constructible_v<T>
size_t BoxContainer<T>::remove_all(const T& item){
	
	size_t removed_count{};
	
	bool item_removed = remove_item(item);
	if(item_removed)
		++removed_count;
	
	while(item_removed == true){
		item_removed = remove_item(item);
		if(item_removed)
			++ removed_count;
	}
	
	return removed_count;
}

// ========================================================================
// ОПЕРАТОРЫ
// ========================================================================

// Оператор += для добавления элементов из другого контейнера
template <typename T> requires std::is_default_constructible_v<T>
void BoxContainer<T>::operator +=(const BoxContainer<T>& operand){
	
	// Убеждаемся, что текущий контейнер может вместить новые элементы
	if( (m_size + operand.size()) > m_capacity)
		expand(m_size + operand.size());
		
	// Копирование элементов
	for(size_t index{} ; index < operand.m_size; ++index){
		m_items [m_size + index] = operand.m_items[index];
	}
	
	m_size += operand.m_size;
}

// Оператор присваивания
template <typename T> requires std::is_default_constructible_v<T>
void BoxContainer<T>::operator =(const BoxContainer<T>& source){
	T *new_items;

	// Проверка на самоприсваивание
	if (this == &source)
            return;
/*
	// Если вместимости разные, настраиваем новый внутренний массив,
	// который соответствует источнику, потому что мы хотим, чтобы объект,
	// которому присваиваем, максимально соответствовал источнику.
	*/
	if (m_capacity != source.m_capacity)
	{ 
	    new_items = new T[source.m_capacity];
	    delete [ ] m_items;
	    m_items = new_items;
	    m_capacity = source.m_capacity;
	}
	
	// Копирование элементов из источника
	for(size_t index{} ; index < source.size(); ++index){
		m_items[index] = source.m_items[index];
	}
	
	m_size = source.m_size;
}

// ========================================================================
// ВНЕШНИЕ ОПЕРАТОРЫ
// ========================================================================

// Оператор + для объединения двух контейнеров
template <typename T> requires std::is_default_constructible_v<T>
BoxContainer<T> operator +(const BoxContainer<T>& left, const BoxContainer<T>& right){
	BoxContainer<T> result(left.size( ) + right.size( ));
	result += left; 
	result += right;
	return result;	
}


//Definitions moved in the header

#endif // BOX_CONTAINER_H

import shapes_numpy
import numpy as np

# Создаем объект Circle
circle = shapes_numpy.Circle(5.0)

# Вычисляем площадь и периметр
print(f"Area: {circle.area()}")
print(f"Perimeter: {circle.perimeter()}")

# Получаем имя фигуры
print(f"Shape name: {circle.getName()}")

# Пример использования функции, которая принимает numpy массив
array = np.array([1.0, 2.0, 3.0, 4.0, 5.0])
result = shapes_numpy.process_array(array)
print(f"Sum of array elements: {result}")
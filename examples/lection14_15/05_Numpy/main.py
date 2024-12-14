import shapes_numpy
import numpy as np

# Создаем объект Circle
circle = shapes_numpy.Circle(5.0)

class MyCircle(shapes_numpy.Circle):
    def __init__(self,n):
        super().__init__(n)
        pass

mc = MyCircle(5)
# Вычисляем площадь и периметр
print(f"Area: {circle.area()}")
print(f"Perimeter: {circle.perimeter()}")

# Получаем имя фигуры
print(f"Shape name: {circle.getName()}")

# Пример использования функции, которая принимает numpy массив
array = np.array([100.0, 2.0, 3.0, 4.0, 5.0,999])
result = shapes_numpy.process_array(array)
print(f"Sum of array elements: {result}")
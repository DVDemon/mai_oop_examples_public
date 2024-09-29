import shapes

# Создаем объект Circle
circle = shapes.Circle(5.0)

# Вычисляем площадь и периметр
print(f"Area: {circle.area()}")
print(f"Perimeter: {circle.perimeter()}")

# Получаем имя фигуры
print(f"Shape name: {circle.getName()}")
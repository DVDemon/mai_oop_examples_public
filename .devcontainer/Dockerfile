# Используем базовый образ с GCC и CMake
FROM gcc:14.2.0

# Устанавливаем необходимые зависимости
RUN apt-get update && apt-get install -y \
    cmake python3 python3-dev python3-pip\
    && rm -rf /var/lib/apt/lists/*

RUN pip install numpy --break-system-packages
# Устанавливаем рабочую директорию
WORKDIR /workspace

#include "person.h"

// Конструктор по умолчанию (используются значения по умолчанию из заголовочного файла)
Person::Person() {
}

// Конструктор с параметрами
// Примечание: здесь используется присваивание в теле конструктора
// Альтернативный способ: использовать список инициализации (закомментирован)
Person::Person(std::string& first_name_param, std::string& last_name_param)
    // : first_name(first_name_param), last_name(last_name_param)  // список инициализации - более эффективный способ
{
    first_name = first_name_param;  // Присваивание в теле конструктора
    last_name = last_name_param;
}

// Метод для вывода информации о персоне в поток
std::ostream& Person::print(std::ostream& out) {
    out << "Person : " << get_first_name()
        << " " << get_last_name() << "]";
    return out;
}

// Деструктор
Person::~Person() {
}

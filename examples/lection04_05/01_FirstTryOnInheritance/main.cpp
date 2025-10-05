#include <iostream>
#include "player.h"

int main() {
    // Создаем объект класса Player (Игрок в баскетбол)
    Player basketball_player("Basketball");
    
    // Устанавливаем имя и фамилию через методы, унаследованные от Person
    basketball_player.set_first_name("John");
    basketball_player.set_last_name("Snow");
    basketball_player.print(std::cout);
    
    // Если вызвать напрямую метод print() объекта Player, выведется полная информация
    // basketball_player.print(std::cout);
    
    // ДЕМОНСТРАЦИЯ ПРОБЛЕМЫ OBJECT SLICING (срезки объектов):
    // При приведении Player к Person происходит "срезка" - теряется часть Player!
    // Создается КОПИЯ только базовой части (Person), а информация о Player (m_game) теряется
    // Поэтому вызовется метод print() класса Person, а не Player
    static_cast<Person>(basketball_player).print(std::cout);
    std::cout << std::endl;
    
    return 0;
}
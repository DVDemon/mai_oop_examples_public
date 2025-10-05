#include <iostream>
#include "player.h"

int main() {
    // Создаем объект класса Player (Игрок в баскетбол) с именем и фамилией
    Player basketball_player("Basketball", "John", "Snow");
    
    // Выводим информацию об игроке
    basketball_player.print(std::cout);
    std::cout << std::endl;
    
    // ДЕМОНСТРАЦИЯ PROTECTED ПОЛЕЙ:
    // В main() мы НЕ можем напрямую обращаться к protected полям!
    // Они доступны только для самого класса и его наследников
    // basketball_player.first_name = "";  // ОШИБКА КОМПИЛЯЦИИ - protected поля недоступны извне
    
    // Для изменения имени/фамилии из main() нужно использовать публичные методы
    basketball_player.set_first_name("Jon");
    basketball_player.set_last_name("Stark");
    
    std::cout << "После изменения имени:" << std::endl;
    basketball_player.print(std::cout);
    
    return 0;
}
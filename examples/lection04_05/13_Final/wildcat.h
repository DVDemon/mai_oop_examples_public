#ifndef WILD_CAT_H
#define WILD_CAT_H
#include "cat.h"

// Класс WildCat (Дикая кошка) - НЕ МОЖЕТ наследоваться от Cat
// Демонстрирует невозможность наследования от final класса
class WildCat /*: public Cat*/  // ЗАКОММЕНТИРОВАНО: Cat помечен как final!
{
public:
    // Конструктор по умолчанию
    WildCat();
    
    // Деструктор (не виртуальный, так как нет наследования)
    ~WildCat();
    
    // ВАЖНО: WildCat НЕ МОЖЕТ наследоваться от Cat, так как Cat помечен как final
    // Если раскомментировать ": public Cat", получим ошибку компиляции
};

#endif // WILD_CAT_H

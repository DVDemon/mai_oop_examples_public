#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <exception>

struct Memento
{
    std::vector<std::string> state;
    Memento(){};
    Memento(const std::vector<std::string> &other) : state(other){};
};

struct Originator
{
    std::stack<Memento> mementos;
    void createMemento(const std::vector<std::string> &state)
    {
        //mementos.push(Memento(state));
        mementos.emplace(state);
    }

    std::vector<std::string> restore(){
        if(!mementos.empty()){
            std::vector<std::string> result = mementos.top().state;
            mementos.pop();
            return result;
        } else throw std::logic_error("undo stack empty");
    }
};

auto main() -> int
{
    Originator origin;
    std::vector<std::string> guests;

    while (true)
    {
        char choice;
        std::string value;
        int index;

        std::cout << "Enter choice:" << std::endl;
        std::cout << "1 - add guest" << std::endl;
        std::cout << "2 - remove guest" << std::endl;
        std::cout << "3 - undo" << std::endl;
        std::cout << "choice>";

        std::cin >> choice;

        switch (choice)
        {
        case '1':
            std::cout << "Enter name:";
            std::cin >> value;
            origin.createMemento(guests);
            guests.push_back(value);
            break;
        case '2':
            std::cout << "Enter index:";
            std::cin >> index;
            if ((index >= 0) && (index < guests.size())){
                origin.createMemento(guests);
                guests.erase(guests.begin() + index);
            }
            break;
        case '3':
            guests = origin.restore();
            break;
        }

        std::cout << std::endl
                  << "Guest list:" << std::endl;
        for (const auto &s : guests)
            std::cout << s << std::endl;
        std::cout << std::endl << std::endl;
    };
    return 1;
}
#include <iostream>
#include <string>
#include <vector>

enum class person_sex_t
{
    Male = 0,
    Female = 1
};

struct Person
{
    std::string name;
    person_sex_t sex;
};

template <class T, class FILTER>
void transform(const std::vector<T> &input,
              std::vector<T> &output, FILTER filter)
{
    for (auto a : input)
        if (filter(a))
            output.push_back(a);
};

template <class T, class ACTION>
void applay(const std::vector<T> &input, ACTION action)
{
    for (auto a : input)
        action(a);
};

auto main() -> int
{
    std::vector<Person> persons{{"Peter", person_sex_t::Male},
                                {"Jane", person_sex_t::Female},
                                {"Tom", person_sex_t::Male},
                                {"Martha", person_sex_t::Female},
                                {"David", person_sex_t::Male},
                                {"Rose", person_sex_t::Female}};

    std::vector<Person> females;
    transform(persons, females, [](const Person &person) {
        if (person.sex == person_sex_t::Female)
            return true;
        else
            return false;
    });

    applay(females, [](const Person &person) {
        std::cout << "[" << person.name << "]" << std::endl;
    });
    return 0;
}
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


auto main() -> int{

    std::vector<std::string> values = {"Bob","Clare","Alex","Diana"};


    // обычное сравнение
    auto compare = [=] (const auto &lhv, const auto& rhv){
                        return lhv<rhv;
                    };
    std::cout << "Simple Sort" << std::endl;
    std::sort(std::begin(values),std::end(values),compare);
    for(const auto& v: values) std::cout << v << std::endl;

    // сделаем injection некоторой функции в сравнение
    auto compare_gen = [=] (auto some_func){
                        return [=] (const auto &lhv, const auto& rhv){
                                return some_func(lhv)<some_func(rhv);
                            };
                    };

    auto reverse_string = [=](const std::string &value){
                    std::string result{};
                    for(int i=value.length();i>=0;--i) result+=value[i];
                    return result;
                };
    
    auto string_length = [=](const std::string &value){
                    return value.length();
                };


    std::cout  << std::endl << "Reverse Sort" << std::endl;
    std::sort(std::begin(values),std::end(values),compare_gen(reverse_string));
    /*
    std::sort(std::begin(values),std::end(values),[=] (const std::string &lhv, const std::string& rhv){
                                return reverse_string(lhv)<reverse_string(rhv);
                            });
    */
    for(const auto& v: values) std::cout << v << std::endl;


    std::cout << std::endl << "Sort by length" << std::endl;
    std::sort(std::begin(values),std::end(values),compare_gen(string_length));
    for(const auto& v: values) std::cout << v << std::endl;

    return 1;
}
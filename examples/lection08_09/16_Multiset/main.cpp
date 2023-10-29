#include <iostream>
#include <set>

void testUnique() {
	std::cout << "\ntestUnique\n";

	std::multiset<int> values;

	auto result = values.insert(42);
	std::cout << *result << std::endl;

	result = values.insert(42);
	std::cout << *result << std::endl;

	std::cout << "values.count(42) = " << values.count(42) << std::endl;

	for(int i=0;i<10;++i){
		auto result = values.insert(42);
		std::cout << &(*result) << std::endl;
	}

    std::cout << "values:" << std::endl;

    for(const auto &v:values)
        std::cout << v << std::endl;

    if(values.find(41)!=std::end(values)){
        std::cout << "Value founded" << std::endl;
    } else  std::cout << "Value not founded" << std::endl;
}

int main() {
	testUnique();

	return 0;
}

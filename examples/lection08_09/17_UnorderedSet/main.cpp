#include <iostream>
#include <string>
#include <unordered_set>

void testUnique() {
	std::cout << "\ntestUnique\n";

	std::unordered_set<int> values;

	auto result = values.insert(42);
	std::cout << *result.first << " inserted: " << result.second << std::endl;

	result = values.insert(42);
	std::cout << *result.first << " inserted: " << result.second << std::endl;
}

void testOrder() {
	std::cout << "\ntestOrder\n";
    
	std::unordered_set<int> values;
	for (int i=0; i<10; ++i)
		values.insert(std::rand()%100);

	for (auto& v : values) 
		std::cout << v << ' ';
	std::cout << std::endl;


	std::unordered_set<std::string> values2 {"AAA","CCC","BBB","DDDD"};
	for (auto& v : values2) 
		std::cout << v << ' ';
}

int main() {
	testUnique();
	testOrder();

	return 0;
}
#include <iostream>
#include <set>
#include <string>

void testUnique() {
	std::cout << "\ntestUnique\n";

	std::set<int> values;

	auto result = values.insert(42);
	std::cout << *result.first << " inserted: " << result.second << std::endl;

	result = values.insert(42);
	std::cout << *result.first << " inserted: " << result.second << std::endl;
}

void testOrder() {
	std::cout << "\ntestOrder\n";

	std::set<int> values;
	for (int i = 10; i >= 0; --i)
		values.insert(i);

	for (auto& v : values) 
		std::cout << v << ' ';
	std::cout << std::endl;
}


void testIterator() {
	std::cout << "\ntestIterator\n";

	std::set<std::string> values = {
		{"Alpha"},
		{"Bravo"},
		{"Charlie"},
		{"Delta"},
		{"Echo"}
	};

	auto iter = values.begin();
	std::cout << *iter << std::endl;

	// Bidirectional
	++iter; 
	--iter;

	// But not random-access
	// iter += 3;

	std::advance(iter, 2);
	std::cout << *iter << std::endl;
}

int main() {
	testUnique();
	testOrder();
	testIterator();

	return 0;
}
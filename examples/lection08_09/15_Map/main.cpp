#include <iostream>
#include <map>
#include <string>

void testUnique() {
	std::cout << "\ntestUnique\n";

	std::map<int, std::string> values;

	auto result = values.insert(std::make_pair(42, "Petia"));
	std::cout << result.first->first << " <-> " << result.first->second << ". inserted: " << result.second << std::endl;

	result = values.insert(std::make_pair(42, "Vasia"));
	std::cout << result.first->first << " <-> " << result.first->second << ". inserted: " << result.second << std::endl;

	values[42]="Kuzia";
	std::cout << "42=" << values[42] << std::endl;

}

void testOrder() {
	std::cout << "\ntestOrder\n";

	std::map<std::string, int> values = {
		{"Vasia", 10},
		{"Petia", 42},
		{"Marina", 17},
		{"Mike", 22},
		{"Alex", 1}
	};

	for(auto& v : values) {
		std::cout << v.first << std::endl;
	}

	for(auto& [k,v] : values) {
		std::cout << k << "," << v << std::endl;
	}
}

void testIterator() {
	std::cout << "\ntestIterator\n";

	std::map<std::string, int> values = {
		{"Alpha", 1},
		{"Bravo", 2},
		{"Charlie", 3},
		{"Delta", 4},
		{"Echo", 5}
	};

	auto get_from_map = [&values](const auto & key) {
		auto ptr = values.find(key);
		return ptr == std::end(values) ? 0 : ptr->second;
	};

	std::cout << "val:" << get_from_map("Alph") << "," << get_from_map("Alpha")<< std::endl;

	auto iter = values.begin();
	std::cout << iter->first << ' ' << iter->second << std::endl;

	// Bidirectional
	++iter; 
	--iter;

	auto it = values.find("Alpha");
	if (it != std::end(values)) {
		std::cout  << "Found:" << it->first << ":" << it->second << std::endl;
	}

	// But not random-access
	// iter += 3;

	std::advance(iter, 2);
	std::cout << iter->first << ' ' << iter->second << std::endl;
}

int main() {
	//testUnique();
	//testOrder();
	testIterator();

	return 0;
}
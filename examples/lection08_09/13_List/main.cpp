#include <list>
#include <iostream>

void testPlacing() {
	std::cout << "\ntestPlacing\n";

	int stackVariable = 0;
	std::list<int> values = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	std::cout << "&stackVariable = " << &stackVariable << std::endl;
	std::cout << "&values        = " << &values << std::endl;
	int *ptr = nullptr;
	for (auto& v : values) {
		std::cout << "&value         = " << &v << std::endl;
		std::cout << "sizeof(ptr)	 = " << sizeof(&v) << std::endl;
		std::cout << "sizeof(value)	 = " << sizeof(v) << std::endl;
		if (ptr) {
			std::cout << "diff = " << &v - ptr << std::endl;
		}
		ptr = &v;		
	}
}

void testIterator() {
	std::cout << "\ntestIterator\n";

	std::list<int> values = {0, 1, 2, 3, 4, 5, 6, 7, 8};

	auto iter = std::next(values.cbegin(), 3);
	std::cout << *iter << std::endl;

	++iter;
	std::cout << *iter << std::endl;

	// Bidirectional iterators
	--iter;
	--iter;
	std::cout << *iter << std::endl;

	// No operator+=
	// iter += 3;
	std::advance(iter, 3);
	std::cout << *iter << std::endl;

	auto iterPos = std::distance(values.cbegin(), iter);
	std::cout << "iterPos = " << iterPos << std::endl;

	std::cout << "one more" << std::endl;
	// operator push_back and push_front
	values.push_back(42);
	values.push_front(42);

	std::cout << "&values[0]       = " << &*values.cbegin() << std::endl;
	std::cout << "&values[iterPos] = " << &*(std::next(values.cbegin(), iterPos)) << std::endl;
	std::cout << "&*iter           = " << &*iter << std::endl;

	// Ooops. Iterator invalid.
	// std::cout << *iter << std::endl;

	auto iter2 = std::next(values.cbegin(), 3);
	std::cout << "*iter2 = " << *iter2 << std::endl;
	std::cout << "one more at the begining" << std::endl;
	values.insert(values.cbegin(), 42);
	std::cout << "*iter2 = " << *iter2 << std::endl;

}

int main() {
	testPlacing();

	testIterator();

	return 0;
}
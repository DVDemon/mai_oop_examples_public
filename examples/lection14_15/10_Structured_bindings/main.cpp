#include <iostream>
#include <map>
#include <string>
#include <tuple>

// Example1 - std::tie (C++11)
void example_map_tie() {
	std::cout << "example_map_tie" << std::endl;

	std::map<int, std::string> map;

	std::map<int, std::string>::iterator iter;
	bool inserted;

	// https://stackoverflow.com/questions/43762651/how-does-stdtie-work
	/*
	namespace detail {
		struct ignore_t {
			template <typename T>
			const ignore_t& operator=(const T&) const { return *this; }
		};
		}
		const detail::ignore_t ignore;
		
		template <typename... Args>
		auto tie(Args&... args) {
			return std::tuple<Args&...>(args...);
		}
	*/
	std::tie(iter, inserted) = map.emplace(0, "Petia");

	std::cout << "First:" << std::endl;
	std::cout << "Key = " << iter->first << " Value = " << iter->second << std::endl;
	std::cout << "Inserted = " << inserted << std::endl; 
	std::cout << std::endl;

	// std::ignore - iter does not needed here
	std::tie(std::ignore, inserted) = map.emplace(0, "Petia");	

	std::cout << "Second:" << std::endl;
	std::cout << "Inserted = " << inserted << std::endl;
	std::cout << std::endl;
}

// Example2 - structured bindings with std::pair (C++17)
void example_map_bindings() {
	std::cout << "example_map_bindings" << std::endl;

	std::map<int, std::string> map;

	{
		// iter and iserted - simple variables
		auto [iter, inserted] = map.emplace(0, "Petia");

		std::cout << "First:" << std::endl;
		std::cout << "Key = " << iter->first << " Value = " << iter->second << std::endl;
		std::cout << "Inserted = " << inserted << std::endl;
		std::cout << std::endl;
	}

	{
		// 1. scope
		// 2. no ignore here
		auto [iter, inserted] = map.emplace(0, "Petia");

		std::cout << "Second:" << std::endl;
		std::cout << "Key = " << iter->first << " Value = " << iter->second << std::endl;
		std::cout << "Inserted = " << inserted << std::endl;
		std::cout << std::endl;
	}

	std::cout << "ranged for" << std::endl;
	map.emplace(1, "Vasia");
	map.emplace(2, "Irina");
	for(auto [key, value] : map) {
		std::cout << "Key = " << key << " Value = " << value << std::endl;
		//key = 42; //- compile error key is const
	}
}





// Example3 - structured bindings with POD (C++17)
// POD structure example
struct POD {
	int age;
	double koeff;
	std::string name;
};

void example_pod_bindings() {
	std::cout << "example_pod_bindings" << std::endl;

	POD pod = {
		41, 
		2.0, 
		"Vasia"
	};

	{
		auto [a, k, n] = pod;

		std::cout << "age = " << a << " koeff = " << k << " name = " << n << std::endl;

		a = 42;
		k = 2.5;
		n = "Petia";
		std::cout << "age = " << a << " koeff = " << k << " name = " << n << std::endl;
	}

	{
		const auto [a, k, n] = pod;
		// a = 42; // compile error because of const
	}
}




// Example4 - structured bindings with private (C++17)
/*
struct StructWithPrivate {
 	StructWithPrivate(int a, int b, int c)
 		: m_a(a), m_b(b), m_c(c) {

 	}
 private:
 	int m_a;
 	int m_b;
 	int m_c;
 };

 void example_private_bindings() {
 	StructWithPrivate object{0,1,2};
 	auto [a, b, c] = object;
 }
 */



// Example5 - structured bindings with private 2 (C++17)
// Let's create tuple!
struct Employee {
	Employee(std::size_t age, const std::string& name, const std::string& secondName)
		: m_age{age}, 
		m_name{name},
		m_secondName{secondName} {

		}

	std::size_t getAge() const { return m_age; }
	std::string getName() const { return m_name; }
	std::string getSecondName() const { return m_secondName; }

private:
	std::size_t m_age;
	std::string m_name;
	std::string m_secondName;
};


// tuple size
namespace std
{
    template<>
    struct tuple_size<Employee>
    {
        static constexpr size_t value = 3;
    };
}

// tuple types
namespace std
{
    template<> struct tuple_element<0, Employee>
    {
        using type = size_t;
    };
 
    template<> struct tuple_element<1, Employee>
    {
        using type = std::string;
    };
 
    template<> struct tuple_element<2, Employee>
    {
        using type = std::string;
    };
}

// Tuple get
template <size_t Position> auto get(const Employee&) = delete;
 
template <> auto get<0>(const Employee& employee)
{
    return employee.getAge();
}
 
template <> auto get<1>(const Employee& employee)
{
    return employee.getName();
}
 
template <> auto get<2>(const Employee& employee)
{
    return employee.getSecondName();
}



void example_private_correct_bindings() {
	std::cout << "example_private_correct_bindings" << std::endl;

	Employee employee{42, "Petia", "Ivanofff"};
	
	auto [age, name, secondName] = employee;
	std::cout << "age = " << age << " name = " << name << " secondName = " << secondName << std::endl;

	age = 42;
	std::cout << "age = " << age << std::endl;
	std::cout << "employee.age = " << employee.getAge() << std::endl;
}



int main() {

	example_map_tie();

	example_map_bindings();

	example_pod_bindings();

	// example_private_bindings(); // compile error

	example_private_correct_bindings();

	return 0;
}


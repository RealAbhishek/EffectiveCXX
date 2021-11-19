#include <iostream>
#include <vector>
#include <typeinfo>
#include <typeindex>

template<typename Container, typename Index>

auto authAndAccess(Container & c, Index& i) -> decltype(c[i])
{
	auto value = c[i];
	std::type_index info(typeid(value));
	auto repr = info.name();
	std::cout << "Trying to see what `operator[]` returns for std::vector<bool>\n";
	std::cout << "The type of the variable value is: " << repr << std::endl;
	std::cout << "Right before returning the value, the value is: " << value << " of type: " << repr << std::endl;
	return value;
}

auto main(int argc, char * argv[]) -> int
{
	std::vector<bool> vecOfBool = {0, 1, 1, 1, 1, 0, 0, 0, 0};
	auto index = 6;
	std::string str("The quiter you become, the more you are able to hear");
	
	auto result = authAndAccess(str, index);
	std::cout << "Value of subscript " << result << std::endl;
}

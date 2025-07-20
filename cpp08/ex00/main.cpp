#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main()
{
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);

	std::vector<int>::iterator it = easyfind(vec, 3);
	std::cout << "Found: " << *it << std::endl;

	// std::find returns end iterator if not found
	it = easyfind(vec, 6);
	if (it == vec.end()) {
		std::cout << "Not found" << std::endl;
	}
	else {
		std::cout << "Found: " << *it << std::endl;
	}

	return 0;
}

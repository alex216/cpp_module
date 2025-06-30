#include <stdint.h>

#include "Data.hpp"
#include "Serializer.hpp"

int main()
{
	Data data("Alex", 42);
	std::cout << "&data:\t" << &data << std::endl;

	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "raw:\t" << raw << std::endl;

	Data *dataPtr = Serializer::deserialize(raw);
	std::cout << "&data:\t" << dataPtr << std::endl;

	std::cout << "Name: " << dataPtr->getName() << ", Age: " << dataPtr->getAge() << std::endl;
}

#include "Serializer.hpp"
#include <iostream>

int main(void)
{
	Data data;
	uintptr_t serialized = Serializer::serialize(&data);
	Data *deserialized = Serializer::deserialize(serialized);

	std::cout << "Original Data address: " << &data << std::endl;
	std::cout << "Serialized Data (uintptr_t): " << serialized << std::endl;
	std::cout << "Deserialized Data address: " << deserialized << std::endl;

	//* Deserialized data member function;
	deserialized->setUserId(42);
	std::cout << "Original Data userId: " << data.getUserId() << std::endl;
	std::cout << "Deserialized Data userId: " << deserialized->getUserId() << std::endl;
	std::cout << "Addresses are " << (deserialized == &data ? "the same" : "different") << std::endl;
	return 0;
}

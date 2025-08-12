#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
	// Create a non-empty Data object
	Data originalData("Hello World");

	// Print original values
	std::cout << "Original data address: " << &originalData << std::endl;
	std::cout << "Original data values: " << originalData.getMessage() << std::endl;

	// Serialize the pointer
	uintptr_t serialized = Serializer::serialize(&originalData);
	std::cout << "Serialized value: " << serialized << std::endl;

	// Deserialize back to pointer
	Data *deserialized = Serializer::deserialize(serialized);
	std::cout << "Deserialized address: " << deserialized << std::endl;

	// Check if the pointers are the same
	if (deserialized == &originalData)
	{
		std::cout << "SUCCESS: Pointers match!" << std::endl;
	}
	else
	{
		std::cout << "ERROR: Pointers don't match!" << std::endl;
	}

	// Verify the data is still accessible and unchanged
	std::cout << "Deserialized data values: " << deserialized->getMessage() << std::endl;

	return 0;
}

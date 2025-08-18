#include <iostream>
#include <Array.hpp>
#include <iter.hpp>

#define MAX_VAL 750
int main(int, char **)
{
	Array<int> numbers(MAX_VAL);
	int *mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	// SCOPE
	{
		Array<int> tmp = numbers;
		// size_t tmp_size = tmp.size();
		// iter(tmp, tmp_size, printElement<int>);
		// std::cout << std::endl;

		Array<int> test(tmp);
		// size_t test_size = tmp.size();
		// iter(test, test_size, printElement<int>);
		// std::cout << std::endl;

		// tmp[0] = 1;
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
		// if (test[i] != tmp[i])
		// {
		// 	std::cerr << "didn't save the same value!!" << std::endl;
		// 	return 1;
		// }
	}
	try
	{
		numbers[-2] = 0;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete[] mirror; //
	return 0;
}

// // Example: Array of pointers for polymorphism
// class Animal
// {
// public:
// 	virtual void speak() const { std::cout << "Animal sound\n"; }
// 	virtual ~Animal() {}
// };

// class Dog : public Animal
// {
// public:
// 	void speak() const override { std::cout << "Woof!\n"; }
// };

// class Cat : public Animal
// {
// public:
// 	void speak() const override { std::cout << "Meow!\n"; }
// };

// int main()
// {
// 	// If you store derived objects(Dog, Cat) in an Array<Animal>, they get object sliced : only the Animal part is stored, and you lose the derived class behavior.
// 	// Array<Animal> *animals[3];
// 	Animal *animals[3];
// 	animals[0] = new Dog();
// 	animals[1] = new Cat();
// 	animals[2] = new Dog();

// 	for (int i = 0; i < 3; ++i)
// 		animals[i]->speak(); // Calls the correct derived class method

// 	for (int i = 0; i < 3; ++i)
// 		delete animals[i]; // Calls the correct derived class method
// }

// // -------TEST CONST access------
// int main()
// {
// 	Array<int> arr(5);
// 	for (unsigned int i = 0; i < arr.size(); ++i)
// 		arr[i] = i * 10;

// 	const Array<int> &constArr = arr;

// 	// Test: Access elements using const operator[]
// 	for (unsigned int i = 0; i < constArr.size(); ++i)
// 		std::cout << constArr[i] << " "; // Should print: 0 10 20 30 40
// 	std::cout << std::endl;

// 	// Uncommenting the next line should cause a compile error:
// 	// constArr[0] = 42;

// 	return 0;
// }

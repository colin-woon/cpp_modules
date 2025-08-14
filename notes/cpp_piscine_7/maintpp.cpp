#include "defaulttypes.tpp"
#include "specialization.tpp"

int main()
{
	Vertex<int> v1(12, 23, 11);
	Vertex<> v2(12, 23, 11);

	std::cout << v1 << std::endl;
	std::cout << v2 << std::endl;

	std::cout << "\n--- Specialization Examples ---" << std::endl;
	// This will use the generic template
	MyClass<float, double> a;

	// This will use the partial specialization for int
	MyClass<bool, int> b;

	// This will use the full specialization for <int, char>
	MyClass<int, char> c;

	return 0;
}

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "./convert <arg>" << std::endl;
		return (0);
	}
	ScalarConverter::convert(av[1]);
}

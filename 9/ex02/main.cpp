#include "PmergeMe.hpp"

bool isInvalidInput(const char *av, long &val)
{
	char *endptr;
	val = strtol(av, &endptr, 10);
	if (*endptr != '\0')
	{
		cerr << "Error: Invalid digit detected" << endl;
		return true;
	}
	if (val < 0)
	{
		cerr << "Error: Negative value detected" << endl;
		return true;
	}
	if (val > UINT_MAX)
	{
		cerr << "Error: Overflow detected" << endl;
		return true;
	}
	return false;
}
int main(int ac, char **av)
{
	if (ac < 2)
		return (0);
	else
	{
		PmergeMe container;
		int i = 1;

		for (; i + 1 < ac; i += 2)
		{
			long first, second;
			if (isInvalidInput(av[i], first) || isInvalidInput(av[i + 1], second))
				return (1);
			container.addToVector(std::make_pair((int)first, (int)second));
		}

		if (i == ac - 1)
		{
			long second;
			if (isInvalidInput(av[i], second))
				return (1);
			container.addToVector(std::make_pair((int)-1, (int)second));
		}
		container.printVector();

		return (0);
	}
}

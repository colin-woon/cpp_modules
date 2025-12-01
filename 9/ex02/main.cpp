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
	if (val > INT_MAX)
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

		for (; i < ac; i++)
		{
			long val;
			if (isInvalidInput(av[i], val))
				return (1);
			// container.addToVector(val);
			container.addToList(val);
		}
		// container.sortVector();
		container.sortList();

		return (0);
	}
}

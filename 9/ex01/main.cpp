#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
		cerr << "Error" << endl;
	else
	{
		RPN rpn;
		bool wasANumber = false;
		try
		{
			for (size_t i = 0; av[1][i]; i++)
			{
				if (isspace(av[1][i]))
				{
					wasANumber = false;
					continue;
				}
				if (!isdigit(av[1][i]) && !rpn.isAllowedOperator(av[1][i]))
				{
					cerr << "Error" << endl;
					return 0;
				}
				if (isdigit(av[1][i]))
				{
					if (wasANumber)
					{
						cerr << "Error" << endl;
						return 0;
					}
					rpn.pushToStack(av[1][i]);
					wasANumber = true;
				}
				else
				{
					rpn.calculate(av[1][i]);
					wasANumber = false;
				}
			}
			cout << rpn.getResult() << endl;
		}
		catch (const exception &e)
		{
			cerr << e.what() << endl;
		}
	}
}

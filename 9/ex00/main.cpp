#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
		cout << "Error: Could not open file" << endl;
	else
	{
		BitcoinExchange *btcExchange;
		try
		{
			btcExchange = new BitcoinExchange("data.csv", ',');
			// btcExchange->getAllDetails();
			btcExchange->calculateExchangeRate(av[1], " | ");
			delete btcExchange;
		}
		catch (const std::exception &e)
		{
			cerr << e.what() << endl;
			delete btcExchange;
		}
	}
}

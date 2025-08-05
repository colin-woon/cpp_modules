/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nested_exception_classes.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 14:10:45 by cwoon             #+#    #+#             */
/*   Updated: 2025/08/05 14:59:33 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdexcept>
#include <iostream>

// Custom exception class inheriting from std::exception
class MyCustomException : public std::exception
{
public:
	const char *what() const throw()
	{
		return "MyCustomException occurred!";
	}
};

void test1()
{
	try
	{
		std::cout << "test1" << std::endl;
		bool error = true;
		// Do stuff
		if (error)
		{
			throw MyCustomException();
		}
		else
		{
			std::cout << "No error occurred." << std::endl;
		}
	}
	catch (const std::exception &e)
	{
		// handle the error
		std::cout << "Caught exception: " << e.what() << std::endl;
		throw;
	}
}

int main()
{
	try
	{
		test1();
	}
	catch (const std::exception &e)
	{
		// handle the error
		std::cerr << "Caught exception in main: " << e.what() << std::endl;
	}
	return 0;
}

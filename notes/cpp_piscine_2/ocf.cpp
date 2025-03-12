/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ocf.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:11:58 by cwoon             #+#    #+#             */
/*   Updated: 2025/03/11 17:47:28 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
orthodox canonical form must haves (for constructors, supposed to have a virtual keyword):
- default constructor
- copy constructor
- destructor
- assignation operator

Optional but useful
- constructor with parameters
- << operator overload for debugging
*/

#include <iostream>
using namespace std;

class Sample
{
public:
	Sample(void) // Default constructor
	{
		cout << "Default constructor called" << endl;
		return;
	}

	Sample(int const n) : _n(n) // Constructor with parameters
	{
		cout << "Parameterized constructor called with " << _n << endl;
		return;
	}

	Sample(Sample const &src) : _n(src.getN()) // Copy constructor
	{
		cout << "Copy constructor called with " << _n << endl;
		return;
	}

	~Sample() // Destructor
	{
		cout << "Destructor called " << _n << endl;
		return;
	}

	Sample &operator=(Sample const &rhs) // Assignation operator
	{
		cout << "Assignment operator called from " << _n << " to " << rhs.getN() << endl;
		// this = &rhs will cause an infinite loop since we are trying to overload the exact same operator when the type is same
		_n = rhs.getN();
		return *this;
	}

	int getN(void) const { return _n; }

private:
	int _n;
};

std::ostream &operator<<(std::ostream &o, Sample const &i) // << operator overload for debugging
{
	o << i.getN();
	return o;
}

int main()
{
	Sample instance;
	Sample instance2(21);
	Sample instance3(instance);

	cout << instance << endl;
	cout << instance2 << endl;
	cout << instance3 << endl;

	instance = instance2;
	cout << instance << endl;

	return 0;
}

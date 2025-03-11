/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_overload.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:34:01 by cwoon             #+#    #+#             */
/*   Updated: 2025/03/11 16:11:07 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
NOTATIONS:

+ 1 1 - prefix AKA functional notation because it looks like a function +(1, 1)
1 + 1 - infix
1 1 + - postfix AKA reverse polish notation
*/

#include <iostream>
using namespace std;

class Sample
{
private:
	int _n;

public:
	Sample(int const n) : _n(n)
	{
		cout << "Constructor called with " << _n << endl;
		return;
	};
	~Sample()
	{
		cout << "Destructor called " << _n << endl;
		return;
	};

	int getN(void) const { return _n; };
	/*
	lhs = left hand side
	rhs = right hand side
	the lhs is invisible, and its usually referring to the object that called the function
	this will be able the change the value
	 */
	Sample &operator=(Sample const &rhs)
	{
		cout << "Assignment operator called from " << _n << " to " << rhs.getN() << endl;
		_n = rhs.getN();
		return *this;
	};
	Sample operator+(Sample const &rhs) const
	{
		cout << "Addition operator called with " << _n << " and " << rhs.getN() << endl;
		return Sample(_n + rhs.getN());
	};
};

/*
overwrites the behaviour of <<
*/
std::ostream &operator<<(std::ostream &o, Sample const &i)
{
	o << "Overload operator called with value: " << i.getN();
	return o;
};

/*
without the operator overload, the code would not work, and the compiler would throw an error
*/
int main()
{
	Sample a(21);
	Sample b(42);
	Sample c = a + b;

	cout << c << endl;
	c = a;
	cout << c << endl;
	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_overloading(adhoc_polymorphism).cp        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:25:33 by cwoon             #+#    #+#             */
/*   Updated: 2025/03/11 14:32:19 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

/*
function overloading must have the same name but different parameters
*/
class Sample
{
public:
	Sample(void)
	{
		cout << "Constructor called" << endl;
		return;
	};
	~Sample(void)
	{
		cout << "Destructor called" << endl;
		return;
	};

	void bar(char const c) const
	{
		cout << "Member function bar called with char: " << c << endl;
		return;
	};
	void bar(int const n) const
	{
		cout << "Member function bar called with int: " << n << endl;
		return;
	};
	void bar(float const f) const
	{
		cout << "Member function bar called with float: " << f << endl;
		return;
	};
	void bar(Sample const &i) const
	{
		(void)i;
		cout << "Member function bar called with Sample: " << endl;
		return;
	};
};

int main(void)
{
	Sample instance;

	instance.bar('a');
	instance.bar(42);
	instance.bar(4.2f);
	instance.bar(instance);

	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sample_class_main.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:17:17 by cwoon             #+#    #+#             */
/*   Updated: 2025/03/04 16:46:33 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sample.class.hpp"
#include <iostream>

using namespace std;
/*
it will construct and destruct automatically
*/
int main()
{
	Sample instance1(42, 'c', 4.2f, 3.14f);
	Sample instance2(24, '+', 0.42f, 3.142f);
	cout << endl;

	cout << "instance2 private var1 was " << instance2.get_private_var1() << endl;
	instance2.set_private_var1(321);
	cout << "instance2 private var1 is now " << instance2.get_private_var1() << endl;
	cout << endl;

	instance1.compare_class(&instance2);
	cout << endl;

	// POINTER SYNTAX
	Sample *instance_pointer = &instance1;
	int Sample::*var1_pointer = NULL;

	var1_pointer = &Sample::var1;

	cout << "instance1 var1 was: " << instance1.var1 << endl;
	instance1.*var1_pointer = 21;
	cout << "instance1 var1 is now: " << instance1.var1 << endl;
	instance_pointer->var1 = 12;
	cout << "instance1 var1 then becomes: " << instance1.var1 << endl;
	instance1.var1 = 6;
	cout << "instance1 var1 finally: " << instance1.var1 << endl;
	cout << endl;

	void (Sample::*f)(int);

	f = &Sample::set_private_var1;

	cout << "instance1 private var1 was " << instance1.get_private_var1() << endl;
	(instance1.*f)(22);
	cout << "instance1 private var1 is now " << instance1.get_private_var1() << endl;
	(instance_pointer->*f)(33);
	cout << "instance1 private var1 then becomes " << instance1.get_private_var1() << endl;
	instance_pointer->set_private_var1(44);
	cout << "instance1 private var1 finally " << instance1.get_private_var1() << endl;
	(instance_pointer->set_private_var1)(55);
	cout << "instance1 private var1 sike " << instance1.get_private_var1() << endl;

	return 0;
}

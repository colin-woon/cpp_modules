/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sample_class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:14:33 by cwoon             #+#    #+#             */
/*   Updated: 2025/03/04 16:22:38 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "sample.class.hpp"
using namespace std;

/*
const before a parameter: "This input won't change inside the function."
const after a method: "This method won’t modify the object."
const before a return type: "The returned value can't be modified."
*/

/*
this is the ONLY way to initialize a static var
*/
int Sample::_nbOfInstances = 0;

Sample::Sample(int param1, char param2, float param3, const float the_pi)
	: var1(param1),
	  var2(param2),
	  var3(param3),
	  pi(the_pi)
{

	cout << "Constructor called" << endl;
	this->_private_var1 = 0;
	cout << "Private Var assigned" << endl;
	this->_nbOfInstances++;
	this->bar();
	this->_privateBar();
	return;
}

Sample::~Sample(void)
{
	cout << "Destructor called" << endl;
	return;
}

int Sample::get_private_var1(void) const
{
	return this->_private_var1;
}

void Sample::set_private_var1(int new_var)
{
	this->_private_var1 = new_var;
	return;
}

/*
Read-only function,
wont modify the value,
if it tries to, will throw an error when compiling, good for debugging
*/
void Sample::bar(void) const
{
	cout << "Member function <bar> called" << endl;
	cout << "var1 is " << this->var1 << endl;
	cout << "var2 is " << this->var2 << endl;
	cout << "var3 is " << this->var3 << endl;
	cout << "pi is " << this->pi << endl;
	cout << "NUMBER OF INSTANCES " << getNbOfInstances() << endl;
	return;
}

int Sample::getNbOfInstances(void)
{
	// return this.
	return Sample::_nbOfInstances;
}

void Sample::_privateBar(void) const
{
	cout << "priv var1 is " << this->_private_var1 << endl;
	return;
}

void Sample::compare_class(Sample *other) const
{
	if (this->_private_var1 > other->get_private_var1())
		cout << "this private var is bigger" << endl;
	else
		cout << "this private var is smaller" << endl;
}

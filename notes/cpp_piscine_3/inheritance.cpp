/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inheritance.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:53:59 by cwoon             #+#    #+#             */
/*   Updated: 2025/03/14 17:07:59 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
/*
To dive deeper:
1. encapsulation level of inheritance (all the attributes inherited from the main class wont necessarily keep the same level of encapsulation)
- private: only the class can access it
- protected: the class and its children can access it
- public: everyone can access it

2. multiple inheritance
- a class can inherit from multiple classes
- can lead to the diamond heritage problem
- C++ uses virtual inheritance to solve this problem
*/

// Quadruped - animal or robot with four legs
class Quadruped
{
private: // private means only this class can access it
	std::string _name;

protected: // protected so that child classes, such as Dog can access it
	const int _legs = 4;

public:
	void run() { std::cout << "Running on " << _legs << " legs" << std::endl; };
};

class Dog : public Quadruped // inheritance
{
private:
	std::string _name;

public:
	Dog(std::string name) : _name(name) {};
	void bark() { std::cout << "Woof! My name is " << _name << " and I have " << _legs << "legs" << std::endl; };
};

int main()
{
	Dog dog("Fido");
	// dog._legs; // error: '_legs' is protected within this context
	dog.bark();
	dog.run();
	return 0;
}

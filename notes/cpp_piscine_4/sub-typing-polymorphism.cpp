/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub-typing-polymorphism.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:51:16 by cwoon             #+#    #+#             */
/*   Updated: 2025/03/28 18:01:50 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// virtual member functions = method
// Virtual enables dynamic resolution of function calls
// without virtual, the function call is resolved at compile time

#include <iostream>
using namespace std;

class Character
{
public:
	// void sayHello(std::string const &target);
	virtual void sayHello(std::string const &target);
};

class Warrior : public Character
{
public:
	void sayHello(std::string const &target) override;
};

void Character::sayHello(std::string const &target)
{
	cout << "Character hello " << target << "!" << endl;
}

void Warrior::sayHello(std::string const &target)
{
	cout << "Warrior hello " << target << "!" << endl;
}

int main()
{
	Warrior *a = new Warrior();
	Character *b = new Warrior();

	a->sayHello("world");
	b->sayHello("world");

	// character is not a warrior
	// but warrior is a character
	// Warrior* c = new Character();

	// Character *d = new Cat();
}

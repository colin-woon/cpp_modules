/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abstract-n-interface.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:38:47 by cwoon             #+#    #+#             */
/*   Updated: 2025/03/28 18:10:23 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

// Abstract class naming convention
// AX or AbstractX or XBase

// Interface naming convention
// IX or InterfaceX

// When using =0, virtual function becomes a pure method, means it has no implementation
// Abstract class cannot be instantiated
// Abstract class can have normal methods
// Abstract class can have attributes

// Interface is a class with only pure virtual functions
// Interface cannot have normal methods
// Interface cannot have attributes

class AbstractCharacter
{
private:
	std::string _name;

public:
	AbstractCharacter(std::string name) : _name(name) {};
	virtual void attack(std::string const &target) = 0;
	void sayHello(std::string const &target) { cout << "Character hello " << target << "!" << endl; };
};
class Warrior : public AbstractCharacter
{
public:
	Warrior(std::string name) : AbstractCharacter(name) {};
	void attack(std::string const &target) override { cout << "Warrior attack " << target << "!" << endl; };
};

class InterfaceCoffeeMaker
{
public:
	virtual void brew() = 0;
	virtual void pour() = 0;
};

int main()
{
	AbstractCharacter *a = new Warrior("hero");
	// AbstractCharacter *a = new Warrior();

	// Abstract class cannot be instantiated
	// AbstractCharacter *b = new AbstractCharacter();

	a->sayHello("world");
	a->attack("world");

	return 0;
}

// Example Where Abstract Class Causes Diamond Problem
// #include <iostream>

// 	class Vehicle
// { // Abstract class (has common behavior)
// public:
// 	virtual void startEngine() const { std::cout << "Engine started!\n"; }
// 	virtual ~Vehicle() {}
// };

// class WaterVehicle : public Vehicle
// { // Inherits Vehicle's methods
// public:
// 	virtual void floatOnWater() const = 0;
// };

// class AirVehicle : public Vehicle
// { // Inherits Vehicle's methods
// public:
// 	virtual void fly() const = 0;
// };

// // ❌ This creates a Diamond Problem!
// class AmphibiousVehicle : public WaterVehicle, public AirVehicle
// {
// public:
// 	void floatOnWater() const override { std::cout << "Floating on water!\n"; }
// 	void fly() const override { std::cout << "Flying in the air!\n"; }
// };

// int main()
// {
// 	AmphibiousVehicle av;
// 	av.startEngine(); // ❌ Ambiguous! Two copies of Vehicle::startEngine()
// }

// How to Fix ? Use Virtual Inheritance
// 	We can fix the diamond problem by using virtual inheritance class Vehicle
// {
// public:
// 	virtual void startEngine() const { std::cout << "Engine started!\n"; }
// 	virtual ~Vehicle() {}
// };

// // ✅ Fix: Virtual Inheritance
// class WaterVehicle : virtual public Vehicle
// {
// public:
// 	virtual void floatOnWater() const = 0;
// };

// class AirVehicle : virtual public Vehicle
// {
// public:
// 	virtual void fly() const = 0;
// };

// class AmphibiousVehicle : public WaterVehicle, public AirVehicle
// {
// public:
// 	void floatOnWater() const override { std::cout << "Floating on water!\n"; }
// 	void fly() const override { std::cout << "Flying in the air!\n"; }
// };

// int main()
// {
// 	AmphibiousVehicle av;
// 	av.startEngine(); // ✅ No ambiguity!
// }

// Using an Interface(✅ Supports Multiple Inheritance)
// 	Interfaces are used when different classes must follow the same structure,
// 	but don’t share code.For example, all vehicles that can fly must have a fly() method, but we don’t define how they fly.

// #include <iostream>

// // Interface for flying capability
// class IFlyable
// {
// public:
// 	virtual void fly() const = 0; // Pure virtual function (no implementation)
// 	virtual ~IFlyable() {}		  // Virtual destructor
// };

// // Interface for floating capability
// class IFloatable
// {
// public:
// 	virtual void floatOnWater() const = 0;
// 	virtual ~IFloatable() {}
// };

// // Airplane implements IFlyable
// class Airplane : public IFlyable
// {
// public:
// 	void fly() const override
// 	{
// 		std::cout << "Airplane is flying high!\n";
// 	}
// };

// // Boat implements IFloatable
// class Boat : public IFloatable
// {
// public:
// 	void floatOnWater() const override
// 	{
// 		std::cout << "Boat is floating on water!\n";
// 	}
// };

// // AmphibiousVehicle implements BOTH IFlyable and IFloatable
// class AmphibiousVehicle : public IFlyable, public IFloatable
// {
// public:
// 	void fly() const override
// 	{
// 		std::cout << "Amphibious vehicle is flying!\n";
// 	}

// 	void floatOnWater() const override
// 	{
// 		std::cout << "Amphibious vehicle is floating!\n";
// 	}
// };

// int main()
// {
// 	Airplane airplane;
// 	Boat boat;
// 	AmphibiousVehicle amphibiousCar;

// 	airplane.fly();
// 	boat.floatOnWater();
// 	amphibiousCar.fly();
// 	amphibiousCar.floatOnWater();

// 	return 0;
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   references.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:27:13 by cwoon             #+#    #+#             */
/*   Updated: 2025/03/06 15:06:28 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
& - is a pointer, that is constant, is always unreferenced, but never void

& vs * (reference vs pointer)
& - if it should always exist, feel free to use it
* - if it should be null at some point, use it
*/

#include <iostream>
// using namespace std;

class Student
{
private:
	std::string _login;

public:
	Student(std::string const &login) : _login(login) { std::cout << "Student created" << std::endl; }
	~Student() { std::cout << "Student destroyed" << std::endl; }

	/* these will be an error,
	cause the returned value is a direct reference to the _login attribute,
	 hence allowing modificaiton when the member function is supposed to be const*/
	// std::string &getLoginRef() const { return this->_login; }
	// std::string *getLoginPtr() const { return &(this->_login); }
	std::string &getLoginRef() { return this->_login; }
	std::string const &getLoginRefConst() const { return this->_login; }
	std::string *getLoginPtr() { return &(this->_login); }
	std::string const *getLoginPtrConst() const { return &(this->_login); }
};

void ft_swap(int *a, int &b)
{
	int temp = *a;
	*a = b;
	b = temp;
}

int main()
{
	int a = 2;
	int b = 3;
	int &bref = b;
	int *aptr = &a;

	std::cout << "ori a: " << *aptr << std::endl;
	std::cout << "ori b: " << bref << std::endl;
	ft_swap(aptr, bref);
	std::cout << "a: " << *aptr << std::endl;
	std::cout << "b: " << bref << std::endl;

	Student non_const_student = Student("non_const_student");

	// NOT MODIFIABLE
	// non_const_student.getLoginPtrConst() = "asdasd";
	// non_const_student.getLoginRefConst() = "asdasd";
	std::cout << "BEFORE " << non_const_student.getLoginRefConst() << std::endl;

	non_const_student.getLoginRef() = "NON_CONST";
	std::cout << "AFTER " << non_const_student.getLoginRefConst() << std::endl;

	*(non_const_student.getLoginPtr()) = "STILL NON_CONST";
	std::cout << "FINAL but memory address " << non_const_student.getLoginPtrConst() << std::endl;
	std::cout << "FINAL" << *(non_const_student.getLoginPtrConst()) << std::endl;

	return 0;
}

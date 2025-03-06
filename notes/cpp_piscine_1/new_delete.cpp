/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_delete.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:16:19 by cwoon             #+#    #+#             */
/*   Updated: 2025/03/06 14:26:02 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

class Student
{
private:
	string _login;

public:
	Student()
	{
		cout << "Student created" << endl;
	};
	~Student()
	{
		cout << "Student destroyed" << endl;
	};
};

/*
malloc - new
free - delete

new - cannot pass any paramters to constructor, just like how malloc works
delete - when freeing an array, add a []
*/
int main()
{
	Student *student = new Student;
	Student *students = new Student[42];
	delete student;
	delete[] students;
	return 0;
}

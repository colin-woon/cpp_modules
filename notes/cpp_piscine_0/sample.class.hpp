/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sample.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:13:48 by cwoon             #+#    #+#             */
/*   Updated: 2025/03/04 16:20:08 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE_CLASS_H
#define SAMPLE_CLASS_H

/*
constructor <class_name>
destructor ~<class_name>

default scope if we dont specify anything
struct - public
class - private
(struct looks exactly like a class, just with the struct word)

accessors for private stuff
- get
- set

static will presist its value across different class instances
*/

class Sample
{
public:
	int var1;
	char var2;
	float var3;
	const float pi;

	Sample(int var1, char var2, float var3, const float the_pi);
	~Sample(void);

	void bar(void) const;
	int get_private_var1(void) const;
	void set_private_var1(int new_var);
	void compare_class(Sample *other_class) const;
	static int getNbOfInstances(void);

private:
	int _private_var1;
	static int _nbOfInstances;

	void _privateBar(void) const;
};

#endif

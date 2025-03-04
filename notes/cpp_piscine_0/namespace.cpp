/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   namespace.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 19:45:45 by cwoon             #+#    #+#             */
/*   Updated: 2025/03/03 15:04:28 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int global_var = 1;
int f(void) { return 2; };

namespace Foo
{
	int global_var = 3;
	int f(void) { return 4; }
}

namespace Bar
{
	int global_var = 5;
	int f(void) { return 6; }
}

namespace Muf = Bar;

int main()
{
	printf("gl_var = %d\n", global_var);
	printf("f = %d\n", f());
	printf("foo gl_var = %d\n", Foo::global_var);
	printf("foo f = %d\n", Foo::f());
	printf("Bar gl_var = %d\n", Bar::global_var);
	printf("Bar f = %d\n", Bar::f());
	printf("Muf gl_var = %d\n", Muf::global_var);
	printf("Muf f = %d\n", Muf::f());
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:49:45 by cwoon             #+#    #+#             */
/*   Updated: 2025/03/14 18:51:59 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(void)
{
	Point a(0, 0);
	Point b(4.2f, 0);
	Point c(0, 4.2f);
	Point point_on_hypotenus(2.1f, 2.1f);
	Point inside(1, 1);
	Point outside(5, 5);

	// if (bsp(a, b, c, point_on_hypotenus))
	// 	std::cout << "Point is inside the triangle" << std::endl;
	// else
	// 	std::cout << "Point is outside the triangle" << std::endl;

	if (bsp(a, b, c, inside))
		std::cout << "Point is inside the triangle" << std::endl;
	else
		std::cout << "Point is outside the triangle" << std::endl;

	// if (bsp(a, b, c, outside))
	// 	std::cout << "Point is inside the triangle" << std::endl;
	// else
	// 	std::cout << "Point is outside the triangle" << std::endl;
	return 0;
}

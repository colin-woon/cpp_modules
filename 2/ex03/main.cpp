/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:49:45 by cwoon             #+#    #+#             */
/*   Updated: 2025/03/14 20:57:59 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(void)
{
	Point a(0, 0);
	Point b(4.2f, 0);
	Point c(0, 4.2f);
	Point point_on_hypotenuse(2.1f, 2.1f);
	Point point_on_vertex(0, 0);
	Point inside(1, 1);
	Point outside(5, 5);

	// Point a(0, 0);
	// Point b(4, 0);					 // Changed from 4.2 to 4
	// Point c(0, 4);					 // Changed from 4.2 to 4
	// Point point_on_hypotenuse(2, 2); // Exact point on hypotenuse, binary-friendly
	// Point point_on_vertex(0, 0);
	// Point inside(1, 1);
	// Point outside(5, 5);

	if (bsp(a, b, c, point_on_hypotenuse))
		std::cout << "Point is inside the triangle" << std::endl;
	else
		std::cout << "Point is outside the triangle" << std::endl;

	if (bsp(a, b, c, inside))
		std::cout << "Point is inside the triangle" << std::endl;
	else
		std::cout << "Point is outside the triangle" << std::endl;

	if (bsp(a, b, c, outside))
		std::cout << "Point is inside the triangle" << std::endl;
	else
		std::cout << "Point is outside the triangle" << std::endl;

	if (bsp(a, b, c, point_on_vertex))
		std::cout << "Point is inside the triangle" << std::endl;
	else
		std::cout << "Point is outside the triangle" << std::endl;

	return 0;
}

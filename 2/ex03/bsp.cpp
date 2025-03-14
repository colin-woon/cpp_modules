/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:12:48 by cwoon             #+#    #+#             */
/*   Updated: 2025/03/14 21:13:48 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*
Formula for a triangle: |x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2)| / 2
Will have to get the absolute value of the result, no negatives
*/
static Fixed getTriangleArea(Point const i, Point const j, Point const point)
{
	Fixed area = ((i.getX() * (j.getY() - point.getY())) +
				  (j.getX() * (point.getY() - i.getY())) +
				  (point.getX() * (i.getY() - j.getY()))) /
				 Fixed(2);

	if (area < Fixed(0))
		area = area * Fixed(-1);

	// std::cout << "Area: " << area << std::endl;
	return area;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed area_abc = getTriangleArea(a, b, c);
	Fixed area_pbc = getTriangleArea(point, b, c);
	Fixed area_apc = getTriangleArea(a, point, c);
	Fixed area_abp = getTriangleArea(a, b, point);

	// Define epsilon as smallest possible value in our fixed-point format
	Fixed epsilon(0.00390625f); // 1/256 (with 8 fractional bits)

	// Check for zero areas (point on edge/vertex) with epsilon
	if ((area_abc < epsilon) ||
		(area_pbc < epsilon) ||
		(area_apc < epsilon) ||
		(area_abp < epsilon))
	{
		std::cout << "Point is on the edge or vertex of the triangle" << std::endl;
		return false;
	}

	// Compare areas with epsilon tolerance
	Fixed diff = (area_pbc + area_apc + area_abp) - area_abc;

	// Shows the inaccuracy of floating-point numbers
	// std::cout << "Area ABC: " << area_abc << std::endl;
	// std::cout << "Area ALL: " << area_pbc + area_apc + area_abp << std::endl;
	// std::cout << "Diff: " << diff << std::endl;

	if (diff < Fixed(0))
		diff = diff * Fixed(-1);
	if (diff <= epsilon)
		return true;
	return false;
}

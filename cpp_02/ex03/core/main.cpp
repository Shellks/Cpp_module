/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 11:36:21 by acarlott          #+#    #+#             */
/*   Updated: 2023/10/05 17:25:19 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"

int main( void ) 
{
	//Test1 - inside the triangle

	std::cout << "Test1: 'inside'- a(0, 0), b(5, 10), c(10, 0), point(3, 4)" << std::endl;
	if (bsp(Point(0, 0), Point(5, 10), Point(10, 0), Point(3, 4)) == true)
		std::cout << "Point is inside the triangle !" << std::endl;
	else
		std::cout << "Point is outside the triangle !" << std::endl;
	std::cout << std::endl;

	//Test2 - on vertex

	std::cout << "Test2: 'vertex' - a(0, 0), b(5, 10), c(10, 0), point(5, 10)" << std::endl;
	if (bsp(Point(0, 0), Point(5, 10), Point(10, 0), Point(5, 10)) == true)
		std::cout << "Point is inside the triangle !" << std::endl;
	else
		std::cout << "Point is outside the triangle !" << std::endl;
	std::cout << std::endl;

	//Test3 - Point is on edge

	std::cout << "Test3: 'edge' - a(0, 0), b(5, 10), c(10, 0), point(2, 4)" << std::endl;
	if (bsp(Point(0, 0), Point(5, 10), Point(10, 0), Point(2, 4)) == true)
		std::cout << "Point is inside the triangle !" << std::endl;
	else
		std::cout << "Point is outside the triangle !" << std::endl;
	std::cout << std::endl;

	//Test4 - Point is outside

	std::cout << "Test4: 'outside' - a(0, 0), b(5, 10), c(10, 0), point(12, 15)" << std::endl;
	if (bsp(Point(0, 0), Point(5, 10), Point(10, 0), Point(12, 15)) == true)
		std::cout << "Point is inside the triangle !" << std::endl;
	else
		std::cout << "Point is outside the triangle !" << std::endl;
	std::cout << std::endl;

	//Test5 - Point is neg

	std::cout << "Test5: 'negative' - a(0, 0), b(5, 10), c(10, 0), point(-10, 4)" << std::endl;
	if (bsp(Point(0, 0), Point(5, 10), Point(10, 0), Point(-10, 4)) == true)
		std::cout << "Point is inside the triangle !" << std::endl;
	else
		std::cout << "Point is outside the triangle !" << std::endl;
	std::cout << std::endl;

	//Test6 - Point is float inside

	std::cout << "Test6: 'inside float' - a(0, 0), b(5, 10), c(10, 0), point(4.4, 8.7)" << std::endl;
	if (bsp(Point(0, 0), Point(5, 10), Point(10, 0), Point(4.4, 8.7)) == true)
		std::cout << "Point is inside the triangle !" << std::endl;
	else
		std::cout << "Point is outside the triangle !" << std::endl;
	std::cout << std::endl;
	return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:03:23 by acarlott          #+#    #+#             */
/*   Updated: 2023/12/18 17:32:10 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/whatever.hpp"
#include <string>

int main(void)
{
	{
		std::cout << MAGENTA << "TEST|" << YELLOW << " INT TYPE:" << RESET << std::endl;
		int x = 21;
		int y = 42;

		std::cout << MAGENTA << "    |" << CYAN << " initial both values" << RESET << std::endl;
		std::cout << MAGENTA << "    |" << RESET << "  -" << CYAN << " x" << RESET << " = " << YELLOW << x << RESET << std::endl;
		std::cout << MAGENTA << "    |" << RESET << "  -" << CYAN << " y" << RESET << " = " << YELLOW << y << RESET << std::endl;
		std::cout << MAGENTA << "    |" << CYAN << " Swapping the 2 values" << RESET << std::endl;
		::swap(x, y);
		std::cout << MAGENTA << "    |" << RESET << "  -" << CYAN << " x" << RESET << " = " << YELLOW << x << RESET << std::endl;
		std::cout << MAGENTA << "    |" << RESET << "  -" << CYAN << " y" << RESET << " = " << YELLOW << y << RESET << std::endl;
		std::cout << MAGENTA << "    |" << CYAN << " Smallest values" << RESET << " between " << YELLOW << x << RESET << " & " << YELLOW << y << RESET << " is: " << YELLOW << ::min(x, y) << RESET << std::endl;
		std::cout << MAGENTA << "    |" << CYAN << " Greatest values" << RESET << " between " << YELLOW << x << RESET << " & " << YELLOW << y << RESET << " is: " << YELLOW << ::max(x, y) << RESET << std::endl;
		std::cout << MAGENTA << "********************************************" << RESET << std::endl;
	}
	{
		std::cout << MAGENTA << "TEST|" << YELLOW << " FLOAT TYPE:" << RESET << std::endl;
		float x = 21.3f;
		float y = 42.3f;

		std::cout << MAGENTA << "    |" << CYAN << " initial both values" << RESET << std::endl;
		std::cout << MAGENTA << "    |" << RESET << "  -" << CYAN << " x" << RESET << " = " << YELLOW << x << RESET << std::endl;
		std::cout << MAGENTA << "    |" << RESET << "  -" << CYAN << " y" << RESET << " = " << YELLOW << y << RESET << std::endl;
		std::cout << MAGENTA << "    |" << CYAN << " Swapping the 2 values" << RESET << std::endl;
		::swap(x, y);
		std::cout << MAGENTA << "    |" << RESET << "  -" << CYAN << " x" << RESET << " = " << YELLOW << x << RESET << std::endl;
		std::cout << MAGENTA << "    |" << RESET << "  -" << CYAN << " y" << RESET << " = " << YELLOW << y << RESET << std::endl;
		std::cout << MAGENTA << "    |" << CYAN << " Smallest values" << RESET << " between " << YELLOW << x << RESET << " & " << YELLOW << y << RESET << " is: " << YELLOW << ::min(x, y) << RESET << std::endl;
		std::cout << MAGENTA << "    |" << CYAN << " Greatest values" << RESET << " between " << YELLOW << x << RESET << " & " << YELLOW << y << RESET << " is: " << YELLOW << ::max(x, y) << RESET << std::endl;
		std::cout << MAGENTA << "********************************************" << RESET << std::endl;
	}
	{
		std::cout << MAGENTA << "TEST|" << YELLOW << " DOUBLE TYPE:" << RESET << std::endl;
		double x = 142.3;
		double y = 121.3;

		std::cout << MAGENTA << "    |" << CYAN << " initial both values" << RESET << std::endl;
		std::cout << MAGENTA << "    |" << RESET << "  -" << CYAN << " x" << RESET << " = " << YELLOW << x << RESET << std::endl;
		std::cout << MAGENTA << "    |" << RESET << "  -" << CYAN << " y" << RESET << " = " << YELLOW << y << RESET << std::endl;
		std::cout << MAGENTA << "    |" << CYAN << " Swapping the 2 values" << RESET << std::endl;
		::swap(x, y);
		std::cout << MAGENTA << "    |" << RESET << "  -" << CYAN << " x" << RESET << " = " << YELLOW << x << RESET << std::endl;
		std::cout << MAGENTA << "    |" << RESET << "  -" << CYAN << " y" << RESET << " = " << YELLOW << y << RESET << std::endl;
		std::cout << MAGENTA << "    |" << CYAN << " Smallest values" << RESET << " between " << YELLOW << x << RESET << " & " << YELLOW << y << RESET << " is: " << YELLOW << ::min(x, y) << RESET << std::endl;
		std::cout << MAGENTA << "    |" << CYAN << " Greatest values" << RESET << " between " << YELLOW << x << RESET << " & " << YELLOW << y << RESET << " is: " << YELLOW << ::max(x, y) << RESET << std::endl;
		std::cout << MAGENTA << "********************************************" << RESET << std::endl;
	}
	{
		std::cout << MAGENTA << "TEST|" << YELLOW << " CHAR TYPE:" << RESET << std::endl;
		char const *x = "string_1";
		char const *y = "string_2";
		std::cout << MAGENTA << "    |" << CYAN << " initial both values" << RESET << std::endl;
		std::cout << MAGENTA << "    |" << RESET << "  -" << CYAN << " x" << RESET << " = " << YELLOW << x << RESET << std::endl;
		std::cout << MAGENTA << "    |" << RESET << "  -" << CYAN << " y" << RESET << " = " << YELLOW << y << RESET << std::endl;
		std::cout << MAGENTA << "    |" << CYAN << " Swapping the 2 values" << RESET << std::endl;
		::swap(x, y);
		std::cout << MAGENTA << "    |" << RESET << "  -" << CYAN << " x" << RESET << " = " << YELLOW << x << RESET << std::endl;
		std::cout << MAGENTA << "    |" << RESET << "  -" << CYAN << " y" << RESET << " = " << YELLOW << y << RESET << std::endl;
		std::cout << MAGENTA << "    |" << CYAN << " Smallest values" << RESET << " between " << YELLOW << x << RESET << " & " << YELLOW << y << RESET << " is: " << YELLOW << ::min(x, y) << RESET << std::endl;
		std::cout << MAGENTA << "    |" << CYAN << " Greatest values" << RESET << " between " << YELLOW << x << RESET << " & " << YELLOW << y << RESET << " is: " << YELLOW << ::max(x, y) << RESET << std::endl;
		std::cout << MAGENTA << "********************************************" << RESET << std::endl;
	}
	// {
	// 	std::cout << "Default test: " << std::endl;
	// 	int a = 2;
	// 	int b = 3;
	// 	::swap( a, b );
	// 	std::cout << "a = " << a << ", b = " << b << std::endl;
	// 	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	// 	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	// 	std::string c = "chaine1";
	// 	std::string d = "chaine2";
	// 	::swap(c, d);
	// 	std::cout << "c = " << c << ", d = " << d << std::endl;
	// 	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	// 	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	// 	return 0;
	// }
}
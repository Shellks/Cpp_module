/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 11:36:21 by acarlott          #+#    #+#             */
/*   Updated: 2023/11/17 11:30:13 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << a << std::endl;
	std::cout << --a << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl;
	std::cout << Fixed::min( a, b ) << std::endl;
	Fixed c( Fixed(10) / 2);
	std::cout << c << std::endl;
	c = (Fixed(10) - Fixed(6));
	std::cout << c << std::endl;
	c = (Fixed(10) + Fixed(6));
	std::cout << c << std::endl;
	std::cout << Fixed::min( c, a ) << std::endl;
	std::cout << Fixed::max( c, a ) << std::endl;
	if (c < a)
		std::cout << "c is lower" << std::endl;
	else
		std::cout << "c is higher" << std::endl;
	if (c > a)
		std::cout << "c is higher" << std::endl;
	else
		std::cout << "c is lower" << std::endl;
	if (a == c)
		std::cout << "is equal" << std::endl;
	else
		std::cout << "is not equal" << std::endl;
	if (a != c)
		std::cout << "is not equal" << std::endl;
	else
		std::cout << "is equal" << std::endl;
	return 0;
}

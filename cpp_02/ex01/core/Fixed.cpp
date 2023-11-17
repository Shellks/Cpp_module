/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 11:36:54 by acarlott          #+#    #+#             */
/*   Updated: 2023/11/17 09:43:31 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

Fixed::Fixed(void) : _FixedValue(0) {
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(Fixed const& src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Fixed::Fixed(int const value) : _FixedValue(value * (1 << this->_FractionnalPart)) {
	std::cout << "Int constructor called" << std::endl;
	return ;
}

Fixed::Fixed(float const value) : _FixedValue(roundf(value * (1 << this->_FractionnalPart))) {
	std::cout << "Float constructor called" << std::endl;
	return ;
}

int		Fixed::toInt( void ) const {
	return (this->_FixedValue / (1 << this->_FractionnalPart));
}

float	Fixed::toFloat( void ) const {
	return ((float)this->_FixedValue / (1 << this->_FractionnalPart));
}

Fixed&	Fixed::operator=(Fixed const& src) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_FixedValue = src.getRawBits();
	return *this;
}

std::ostream&	operator<<(std::ostream& out, Fixed const& src) {
	out << src.toFloat();
	return out;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
	return ;
}

int	Fixed::getRawBits( void ) const {
	return this->_FixedValue;
}

void	Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_FixedValue = raw;
	return ;
}

int const	Fixed::_FractionnalPart = 8;
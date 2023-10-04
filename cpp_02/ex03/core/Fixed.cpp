/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 11:36:54 by acarlott          #+#    #+#             */
/*   Updated: 2023/10/04 18:33:44 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

Fixed::Fixed(void) : _FixedValue(0) {
	return ;
}

Fixed::Fixed(Fixed const& src) : _FixedValue(0) {
	*this = src;
	return ;
}

Fixed::Fixed(int const value) : _FixedValue(value * (1 << this->_FractionnalPart)) {
	return ;
}

Fixed::Fixed(float const value) : _FixedValue(roundf(value * (1 << this->_FractionnalPart))) {
	return ;
}

Fixed::~Fixed(void) {
	return ;
}

int		Fixed::toInt( void ) const {
	return (this->_FixedValue / (1 << this->_FractionnalPart));
}

float	Fixed::toFloat( void ) const {
	return ((float)this->_FixedValue / (1 << this->_FractionnalPart));
}

int	Fixed::getRawBits( void ) const {
	return this->_FixedValue;
}

void	Fixed::setRawBits( int const raw ) {
	this->_FixedValue = raw;
	return ;
}

Fixed&	Fixed::operator=(Fixed const& src) {
	this->_FixedValue = src.getRawBits();
	return *this;
}

std::ostream&	operator<<(std::ostream& out, Fixed const& src) {
	out << src.toFloat();
	return out;
}

Fixed	Fixed::operator+(Fixed const& src) const {
	return Fixed(this->toFloat() + src.toFloat());
}

Fixed	Fixed::operator-(Fixed const& src) const {
	return Fixed(this->toFloat() - src.toFloat());
}

Fixed	Fixed::operator*(Fixed const& src) const {
	return Fixed(this->toFloat() * src.toFloat());
}

Fixed	Fixed::operator/(Fixed const& src) const {
	return Fixed(this->toFloat() / src.toFloat());
}


bool	Fixed::operator<(Fixed const& src) const {
	return (this->_FixedValue < src.getRawBits());
}

bool	Fixed::operator<=(Fixed const& src) const {
	return (this->_FixedValue <= src.getRawBits());
}

bool	Fixed::operator>(Fixed const& src) const {
	return (this->_FixedValue > src.getRawBits());
}

bool	Fixed::operator>=(Fixed const& src) const {
	return (this->_FixedValue >= src.getRawBits());
}

bool	Fixed::operator==(Fixed const& src) const {
	return (this->_FixedValue == src.getRawBits());
}

bool	Fixed::operator!=(Fixed const& src) const {
	return (this->_FixedValue == src.getRawBits());
}

Fixed&	Fixed::operator++(void) {
	this->_FixedValue++;
	return (*this);
}

Fixed&	Fixed::operator--(void) {
	this->_FixedValue++;
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed	tmp = *this;
	this->_FixedValue++;
	return (tmp);
}

Fixed	Fixed::operator--(int) {
	Fixed	tmp = *this;
	this->_FixedValue--;
	return (tmp);
}

Fixed	Fixed::min(Fixed& ref1, Fixed& ref2) {
	if (ref1.getRawBits() < ref2.getRawBits())
		return (ref1);
	return (ref2);
}

Fixed	Fixed::min(Fixed const& ref1, Fixed const& ref2) {
	if (ref1.getRawBits() < ref2.getRawBits())
		return (ref1);
	return (ref2);
}

Fixed	Fixed::max(Fixed& ref1, Fixed& ref2) {
	if (ref1.getRawBits() > ref2.getRawBits())
		return (ref1);
	return (ref2);
}

Fixed	Fixed::max(Fixed const& ref1, Fixed const& ref2) {
	if (ref1.getRawBits() > ref2.getRawBits())
		return (ref1);
	return (ref2);
}

int const	Fixed::_FractionnalPart = 8;
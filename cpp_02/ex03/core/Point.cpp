/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:55:54 by acarlott          #+#    #+#             */
/*   Updated: 2023/10/04 19:16:03 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "point.hpp"

Point::Point(void) : _x(0), _y(0) {
	return ;
}

Point::Point(float const x, float const y) : _x(x), _y(y) {
	return ;
}

Point::Point(Point const& src) : _x(0), _y(0) {
	*this = src;
	return ;
}

Point::~Point(void) {
	return ;
}

Fixed	Point::getX(void) const {
	return this->_x;
}

Fixed	Point::getY(void) const {
	return this->_y;
}
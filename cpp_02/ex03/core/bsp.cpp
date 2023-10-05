/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:07:02 by acarlott          #+#    #+#             */
/*   Updated: 2023/10/05 17:29:32 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"

static Fixed	check_negative(Fixed value) {
	if (value < 0)
		return (value * -1);
	return value;
}

Fixed	getArea(Point const* a, Point const* b, Point const* c)
{
	return (Fixed(check_negative((a->getX() * (b->getY() - c->getY())) \
	+ ((b->getX() * (c->getY() - a->getY()))) \
	+ ((c->getX() * (a->getY() - b->getY()))) / 2)));
}

bool	bsp(Point const a, Point const b, Point const c, Point const point) 
{
	Fixed	ABC_area;
	Fixed	PAB_area;
	Fixed	PBC_area;
	Fixed	PCA_area;

	ABC_area = getArea(&a, &b, &c);
	PAB_area = getArea(&point, &b, &a);
	PBC_area = getArea(&point, &b, &c);
	PCA_area = getArea(&point, &a, &c);

	if (ABC_area == (PAB_area + PBC_area + PCA_area) \
	&& PAB_area != 0 && PBC_area != 0 && PCA_area != 0)
		return true;
	return false;
}
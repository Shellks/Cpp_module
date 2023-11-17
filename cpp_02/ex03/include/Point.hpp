/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:50:38 by acarlott          #+#    #+#             */
/*   Updated: 2023/11/17 16:16:45 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		Fixed const	_x;
		Fixed const	_y;

	
	public:
		Point(void);
		Point(float const x, float const y);
		Point(Point const& src);
		~Point(void);

		Fixed	getX(void) const;
		Fixed	getY(void) const;
		Point&	operator=(Point const& src);
};

bool	bsp( Point const a, Point const b, Point const c, Point const point);
Fixed	getArea(Point const* a, Point const* b, Point const* c);

#endif

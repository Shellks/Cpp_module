/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:50:38 by acarlott          #+#    #+#             */
/*   Updated: 2023/10/04 19:16:10 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		Fixed const&	_x;
		Fixed const&	_y;
	
	public:
		Point(void);
		Point(float const x, float const y);
		Point(Point const& src);
		~Point(void);

		Fixed	getX(void) const;
		Fixed	getY(void) const;
		Point&	operator=(Point const& src);
};

#endif
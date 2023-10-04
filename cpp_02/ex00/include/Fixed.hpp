/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 11:35:37 by acarlott          #+#    #+#             */
/*   Updated: 2023/10/04 15:23:02 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int					_FixedValue;
		static int const	_FractionnalPart;

	public:
		Fixed(void);
		Fixed(Fixed const& src);
		~Fixed(void);

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		Fixed&	operator=(Fixed const& src);
};

#endif
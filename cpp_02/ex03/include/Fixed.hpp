/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 11:35:37 by acarlott          #+#    #+#             */
/*   Updated: 2023/11/17 11:34:04 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int					_FixedValue;
		static int const	_FractionnalPart;

	public:
		Fixed(void);
		Fixed(int const value);
		Fixed(float const value);
		Fixed(Fixed const& src);
		~Fixed(void);

		int				getRawBits( void ) const;
		void			setRawBits( int const raw );
		float			toFloat( void ) const;
		int				toInt( void ) const;
		
		static Fixed		min(Fixed& ref1, Fixed& ref2);
		static Fixed		min(Fixed const& ref1, Fixed const& ref2);
		static Fixed		max(Fixed& ref1, Fixed& ref2);
		static Fixed		max(Fixed const& ref1, Fixed const& ref2);

		Fixed&	operator=(Fixed const& src);

		Fixed	operator+(Fixed const& src) const;
		Fixed	operator-(Fixed const& src) const;
		Fixed	operator*(Fixed const& src) const;
		Fixed	operator/(Fixed const& src) const;

		bool	operator<(Fixed const& src) const;
		bool	operator<=(Fixed const& src) const;
		bool	operator>(Fixed const& src) const;
		bool	operator>=(Fixed const& src) const;
		bool	operator==(Fixed const& src) const;
		bool	operator!=(Fixed const& src) const;

		Fixed&	operator++(void);
		Fixed&	operator--(void);
		Fixed	operator++(int	value);
		Fixed	operator--(int	value);
};

std::ostream&	operator<<(std::ostream& out, Fixed const& src);

#endif

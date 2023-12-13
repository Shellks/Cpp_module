/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:55:00 by acarlott          #+#    #+#             */
/*   Updated: 2023/12/13 13:09:46 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>
# include "Brain.hpp"

class Animal
{
	public :
		Animal();
		Animal( std::string const type_name );
		Animal( Animal const& src );
		virtual ~Animal();

		virtual Animal&			operator=( Animal const& src );
		
		std::string		getType(void) const;
		virtual void	makeSound(void) const;
		virtual Brain	*getBrain(void) const;

	protected :
		std::string	type;
};

#endif

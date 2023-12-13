/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:06:03 by acarlott          #+#    #+#             */
/*   Updated: 2023/12/13 13:08:06 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog( Dog const & src );
		Dog( Animal const & src );
		~Dog();

		Dog &		operator=( Dog const & src );
		Animal &	operator=( Animal const & src );
		
		void	makeSound(void) const;
		Brain	*getBrain(void) const;

	private:
		Brain	*_brain;

};

#endif

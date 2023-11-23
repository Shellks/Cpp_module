/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:06:00 by acarlott          #+#    #+#             */
/*   Updated: 2023/11/23 16:04:37 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{

	public:
		Cat();
		Cat( Cat const & src );
		Cat( Animal const & src );
		~Cat();

		Cat &	operator=( Cat const & src );
		Animal &	operator=( Animal const & src );
		
		void	makeSound(void) const;
		Brain	*getBrain(void) const;

	private:
		Brain	*_brain;

};

#endif

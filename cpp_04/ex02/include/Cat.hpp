/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:06:00 by acarlott          #+#    #+#             */
/*   Updated: 2023/11/24 10:27:19 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{

public:
	Cat();
	Cat(Cat const &src);
	Cat(AAnimal const &src);
	~Cat();

	Cat &operator=(Cat const &src);
	AAnimal &operator=(AAnimal const &src);

	void makeSound(void) const;
	Brain *getBrain(void) const;

private:
	Brain *_brain;
};

#endif

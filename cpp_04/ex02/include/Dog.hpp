/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:06:03 by acarlott          #+#    #+#             */
/*   Updated: 2023/11/24 10:28:10 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
public:
	Dog();
	Dog(Dog const &src);
	Dog(AAnimal const &src);
	~Dog();

	Dog &operator=(Dog const &src);
	AAnimal &operator=(AAnimal const &src);

	void makeSound(void) const;
	Brain *getBrain(void) const;

private:
	Brain *_brain;
};

#endif

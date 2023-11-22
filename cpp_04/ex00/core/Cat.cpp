/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:06:11 by acarlott          #+#    #+#             */
/*   Updated: 2023/11/22 15:08:17 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat default constructor called!" << std::endl;
}

Cat::Cat( const Cat & src ) : Animal(src) {
	std::cout << "Cat copy constructor called!" << std::endl;
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat() {
	std::cout << "Cat destructor called!" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat &	Cat::operator=( Cat const & src ) {
	if ( this != &src ) {
		this->type = src.getType();
	}
	return *this;
}

/* ************************************************************************** */

void	Cat::makeSound(void) const {
	std::cout << "Meowww !" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:06:08 by acarlott          #+#    #+#             */
/*   Updated: 2023/11/23 16:52:57 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog() : Animal("Dog") {
	std::cout << "Cat default constructor called!" << std::endl;
}

Dog::Dog( const Dog & src ) : Animal(src) {
	std::cout << "Cat copy constructor called!" << std::endl;
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog() {
	std::cout << "Dog destructor called !" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog &				Dog::operator=( Dog const & src ) {
	if ( this != &src ) {
		this->type = src.type;
	}
	return *this;
}

/* ************************************************************************** */

void	Dog::makeSound(void) const {
	std::cout << "Wouff Wouff !" << std::endl;
}

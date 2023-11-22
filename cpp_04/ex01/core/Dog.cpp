/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:06:08 by acarlott          #+#    #+#             */
/*   Updated: 2023/11/22 16:18:06 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog() : Animal("Dog") {
	this->_brain = new Brain();
	std::cout << "Dog default constructor called!" << std::endl;
}

Dog::Dog( const Dog & src ) : Animal(src) {
	std::cout << "Dog copy constructor called!" << std::endl;
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog() {
	delete this->_brain;
	std::cout << "Dog destructor called!" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog &				Dog::operator=( Dog const & src ) {
	delete this->_brain;
	this->type = src.getType();
	this->_brain = new Brain(*src._brain);
	return *this;
}

/* ************************************************************************** */

void	Dog::makeSound(void) const {
	std::cout << "Wouff Wouff !" << std::endl;
}
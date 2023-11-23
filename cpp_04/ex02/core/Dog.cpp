/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:06:08 by acarlott          #+#    #+#             */
/*   Updated: 2023/11/23 17:27:13 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog default constructor called!" << std::endl;
	this->_brain = new Brain();
}

Dog::Dog( const Dog & src ) : Animal(src) {
	std::cout << "Dog copy constructor from Dog called!" << std::endl;
	this->type = src.getType();
	this->_brain = new Brain(*src.getBrain());
}

Dog::Dog( const Animal & src ) : Animal(src) {
	std::cout << "Dog copy constructor from Animal called!" << std::endl;
	this->type = src.getType();
	this->_brain = new Brain(*src.getBrain());
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

Animal	&Dog::operator=( Animal const & src ) {
	if (this != &src) {
		delete this->_brain;
		this->type = src.getType();
		this->_brain = new Brain(*src.getBrain());
	}
	return *this;
}

Dog	&Dog::operator=( Dog const & src ) {
	if (this != &src) {
		delete this->_brain;
		this->type = src.getType();
		this->_brain = new Brain(*src.getBrain());
	}
	return *this;
}

/* ************************************************************************** */

void	Dog::makeSound(void) const {
	std::cout << "Wouff Wouff !" << std::endl;
}

Brain	*Dog::getBrain(void) const {
	return (this->_brain);
}

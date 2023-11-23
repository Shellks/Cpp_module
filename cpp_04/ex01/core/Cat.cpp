/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:06:11 by acarlott          #+#    #+#             */
/*   Updated: 2023/11/23 16:41:05 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat() : Animal("Cat") {
	this->_brain = new Brain();
	std::cout << "Cat default constructor called!" << std::endl;
}

Cat::Cat( const Cat & src ) : Animal(src) {
	std::cout << "Cat copy constructor called!" << std::endl;
	this->_brain = new Brain(*src.getBrain());
	this->type = src.getType();
}

Cat::Cat( const Animal & src ) : Animal(src) {
	std::cout << "Dog copy constructor called!" << std::endl;
	this->_brain = new Brain(*src.getBrain());
	this->type = src.getType();
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat() {
	delete _brain;
	std::cout << "Cat destructor called!" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Animal	&Cat::operator=( Animal const & src ) {
	if (this != &src) {
		delete this->_brain;
		this->type = src.getType();
		this->_brain = new Brain(*src.getBrain());
	}
	return *this;
}

Cat &	Cat::operator=( Cat const & src ) {
	if (this != &src) {
		delete this->_brain;
		this->type = src.getType();
		this->_brain = new Brain(*src.getBrain());
	}
	return *this;
}

/* ************************************************************************** */

void	Cat::makeSound(void) const {
	std::cout << "Meowww !" << std::endl;
}

Brain	*Cat::getBrain(void) const {
	return (this->_brain);
}

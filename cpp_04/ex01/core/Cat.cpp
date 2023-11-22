/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:06:11 by acarlott          #+#    #+#             */
/*   Updated: 2023/11/22 16:18:25 by acarlott         ###   ########lyon.fr   */
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
	*this = src;
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

Cat &	Cat::operator=( Cat const & src ) {
	delete this->_brain;
	this->type = src.getType();
	this->_brain = new Brain(*src._brain);
	return *this;
}

/* ************************************************************************** */

void	Cat::makeSound(void) const {
	std::cout << "Meowww !" << std::endl;
}

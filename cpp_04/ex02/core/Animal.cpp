/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:06:15 by acarlott          #+#    #+#             */
/*   Updated: 2023/11/23 17:35:26 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Animal::Animal() : type("None") {
	std::cout << "Animal default constructor called!" << std::endl;
}

Animal::Animal( std::string const type_name ) : type(type_name) {
	std::cout << "Animal string constructor called!" << std::endl;
}

Animal::Animal( const Animal & src ) {
	std::cout << "Animal copy constructor called!" << std::endl;
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Animal::~Animal() {
		std::cout << "Animal destructor called!" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Animal &	Animal::operator=( Animal const & src ) {
	if (this != &src) {
		this->type = src.type;
	}
	return *this;
}

/* ************************************************************************** */

std::string	Animal::getType(void) const {
	return (this->type);
}

void	Animal::makeSound(void) const {
	std::cout << "a strange & indescribable animal sound is heard !" << std::endl;
}

Brain	*Animal::getBrain(void) const {
	std::cout << "No brain found.. wtf ??" << std::endl;
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:31:00 by acarlott          #+#    #+#             */
/*   Updated: 2023/11/22 14:54:14 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongAnimal::WrongAnimal() : type("WrongNone"){
}

WrongAnimal::WrongAnimal(std::string const type_name) : type(type_name){
}

WrongAnimal::WrongAnimal( const WrongAnimal & src ) {
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongAnimal::~WrongAnimal() {
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongAnimal &	WrongAnimal::operator=( WrongAnimal const & src ) {
	if ( this != &src ) {
		this->type = src.getType();
	}
	return *this;
}

/* ************************************************************************** */

std::string	WrongAnimal::getType(void) const {
	return (this->type);
}

void	WrongAnimal::makeSound(void) const {
	std::cout << "The sounds of a WrongAnimal is heard !" << std::endl;
}

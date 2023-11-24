/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:25:50 by acarlott          #+#    #+#             */
/*   Updated: 2023/11/24 15:09:09 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Ice::Ice() : AMateria("ice") {
	std::cout << "Ice materia created !" << std::endl;
}

Ice::Ice( const Ice & src ) {
	std::cout << "Copy of ice materia created !" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Ice::~Ice() {
	std::cout << "Ice materia destroyed !" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Ice &	Ice::operator=( Ice const & src ) {
	if (this != &src) {
		this->type = src.type;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

AMateria* Ice::clone() const {
	std::cout << "Cloning ice materia.." << std::endl;
	AMateria	*clone = new Ice();
	return (clone);
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.name << " *" << std::endl;
}

std::string const &	Ice::getType() const {
	return (this->type);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */

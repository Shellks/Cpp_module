/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:25:53 by acarlott          #+#    #+#             */
/*   Updated: 2023/11/24 13:36:56 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cure::Cure() : AMateria("cure") {
	std::cout << "Cure materia created !" << std::endl;
}

Cure::Cure( const Cure & src ) {
	std::cout << "Copy of cure materia created !" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cure::~Cure() {
	std::cout << "Cure materia destroyed !" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cure &	Cure::operator=( Cure const & src ) {
	if (this != &src) {
		this->type = src.type;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

AMateria* Cure::clone() const {
	std::cout << "Cloning cure materia.." << std::endl;
	AMateria	*clone = new Cure();
	return (clone);
}

void Cure::use(ICharacter& target) {
		std::cout << "* heals " << target.name << "’s wounds *" << std::endl;
}

std::string const &	Cure::getType() const {
	return (this->type);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
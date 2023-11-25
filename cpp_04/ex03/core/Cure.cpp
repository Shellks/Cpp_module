/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:25:53 by acarlott          #+#    #+#             */
/*   Updated: 2023/11/25 20:37:22 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cure.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cure::Cure() : AMateria("cure")
{
}

Cure::Cure(const Cure &src) : AMateria("cure")
{
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cure::~Cure()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cure &Cure::operator=(Cure const &src)
{
	if (this != &src)
		this->type = src.type;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

AMateria *Cure::clone() const
{
	std::cout << "Cloning cure materia.." << std::endl;
	AMateria *clone = new Cure(*this);
	return (clone);
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}

std::string const &Cure::getType() const
{
	return (this->type);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */

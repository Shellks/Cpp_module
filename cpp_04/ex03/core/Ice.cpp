/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:25:50 by acarlott          #+#    #+#             */
/*   Updated: 2023/12/13 13:26:26 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Ice.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Ice::Ice() : AMateria("ice")
{
}

Ice::Ice(Ice const &src) : AMateria("ice")
{
	(void)src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Ice::~Ice()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Ice &Ice::operator=(Ice const &src)
{
	(void)src;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

AMateria *Ice::clone() const
{
	std::cout << "Cloning ice materia.." << std::endl;
	AMateria *clone = new Ice(*this);
	return (clone);
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const &Ice::getType() const
{
	return (this->type);
}

/* ************************************************************************** */

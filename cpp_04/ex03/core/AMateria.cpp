/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:51:34 by acarlott          #+#    #+#             */
/*   Updated: 2023/12/02 10:13:08 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AMateria.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AMateria::AMateria() : type("None"), isAssign(false)
{
}

AMateria::AMateria(std::string const &type) : type(type), isAssign(false)
{
}

AMateria::AMateria(const AMateria &src)
{
	this->type = "None";
	this->isAssign = false;
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AMateria::~AMateria()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AMateria &AMateria::operator=(AMateria const &src)
{
	(void)src;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void AMateria::use(ICharacter &target)
{
	std::cout << this->getType() << " used on " << target.getName() << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/
std::string const &AMateria::getType() const
{
	return (this->type);
}

/* ************************************************************************** */

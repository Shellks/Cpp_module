/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:06:15 by acarlott          #+#    #+#             */
/*   Updated: 2023/11/23 17:35:26 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AAnimal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AAnimal::AAnimal() : type("None")
{
	std::cout << "AAnimal default constructor called!" << std::endl;
}

AAnimal::AAnimal(std::string const type_name) : type(type_name)
{
	std::cout << "AAnimal string constructor called!" << std::endl;
}

AAnimal::AAnimal(const AAnimal &src)
{
	std::cout << "AAnimal copy constructor called!" << std::endl;
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called!" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AAnimal &AAnimal::operator=(AAnimal const &src)
{
	if (this != &src)
	{
		this->type = src.type;
	}
	return *this;
}

/* ************************************************************************** */

std::string AAnimal::getType(void) const
{
	return (this->type);
}

void AAnimal::makeSound(void) const
{
	std::cout << "a strange & indescribable AAnimal sound is heard !" << std::endl;
}

Brain *AAnimal::getBrain(void) const
{
	std::cout << "No brain found.. wtf ??" << std::endl;
	return (NULL);
}

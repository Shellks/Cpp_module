/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 19:56:24 by acarlott          #+#    #+#             */
/*   Updated: 2023/11/28 16:45:17 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/MateriaSource.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->_invMateriaSrc[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_invMateriaSrc[i] && this->_invMateriaSrc[i]->isDeleted == false)
		{
			this->_invMateriaSrc[i]->isDeleted = true;
			delete this->_invMateriaSrc[i];
			this->_invMateriaSrc[i] = NULL;
		}
	}
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

MateriaSource &MateriaSource::operator=(MateriaSource const &src)
{
	if (this != &src)
	{
		for (int i = 0; i < 4; i++)
		{
			if (src._invMateriaSrc[i])
			{
				if (this->_invMateriaSrc[i])
					delete this->_invMateriaSrc[i];
				this->_invMateriaSrc[i] = src._invMateriaSrc[i]->clone();
			}
			else
				this->_invMateriaSrc[i] = NULL;
		}
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->_invMateriaSrc[i])
		{
			this->_invMateriaSrc[i] = m;
			std::cout << m->getType() << " materia learned !" << std::endl;
			return;
		}
	}
	delete m;
	std::cout << "MateriaSource inventory is already full" << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_invMateriaSrc[i] && this->_invMateriaSrc[i]->getType() == type)
		{
			AMateria *newMateria = this->_invMateriaSrc[i]->clone();
			std::cout << type << " materia created !" << std::endl;
			return (newMateria);
		}
	}
	std::cout << "Unknow materia type" << std::endl;
	return (NULL);
}

/* ************************************************************************** */

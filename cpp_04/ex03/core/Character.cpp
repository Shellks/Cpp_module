/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:08:52 by acarlott          #+#    #+#             */
/*   Updated: 2023/12/02 11:08:24 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Character.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Character::Character()
{
	for (int i = 0; i < 4; i++)
		this->_invMateria[i] = NULL;
	this->_trashBag = NULL;
	this->_trashBagSize = 0;
	std::cout << "A new unknow hero appears !" << std::endl;
}

Character::Character(std::string name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		this->_invMateria[i] = NULL;
	this->_trashBag = NULL;
	this->_trashBagSize = 0;
	std::cout << this->_name << " the great hero appears !" << std::endl;
}

Character::Character(const Character &src)
{
	for (int i = 0; i < 4; i++)
		this->_invMateria[i] = NULL;
	this->_trashBag = NULL;
	this->_trashBagSize = 0;
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Character::~Character()
{
	int i = 0;
	for (; i < 4; i++)
		if (this->_invMateria[i])
			delete this->_invMateria[i];
	for (i = 0; i < this->_trashBagSize; i++)
		if (this->_trashBag[i])
			delete _trashBag[i];
	delete[] this->_trashBag;
	std::cout << this->_name << " has been destroyed by evil forces !" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Character &Character::operator=(Character const &src)
{
	if (this != &src)
	{
		this->_name = src.getName();
		this->_trashBagSize = src._trashBagSize;
		if (!src._trashBag)
			this->_trashBag = NULL;
		else
			this->_trashBag = new AMateria *[this->_trashBagSize];
		int i = 0;
		for (; i < 4; i++)
		{
			if (this->_invMateria[i])
				delete this->_invMateria[i];
			this->_invMateria[i] = src._invMateria[i]->clone();
		}
		for (i = 0; i < this->_trashBagSize; i++)
			this->_trashBag[i] = src._trashBag[i];
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Character::equip(AMateria *m)
{
	int i = 0;
	if (!m)
		return;
	for (; i < 4; i++)
	{
		if (m->isAssign == true)
		{
			std::cout << "this materia is already equipped" << std::endl;
			return;
		}
		if (!this->_invMateria[i])
		{
			this->_invMateria[i] = m;
			this->_invMateria[i]->isAssign = true;
			std::cout << m->getType() << " materia succesfully added to " << this->getName() << " materia inventory slot \"" << i << "\"" << std::endl;
			return;
		}
	}
	this->dropMateria(m);
	std::cout << "Materia inventory is full" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Wrong index \"0 to 3\", only 4 materia slot are available" << std::endl;
		return;
	}
	if (idx < 4 && this->_invMateria[idx])
	{
		this->dropMateria(this->_invMateria[idx]);
		std::cout << "Materia " << this->_invMateria[idx]->getType() << " has been dropped" << std::endl;
		this->_invMateria[idx] = NULL;
		return;
	}
	std::cout << "Materia slot choosen is empty, add new one with \"equip\" action" << std::endl;
}

void Character::dropMateria(AMateria *toDrop)
{
	AMateria **newTrashBag;
	int i = 0;

	if (!toDrop)
		return;
	this->_trashBagSize++;
	newTrashBag = new AMateria *[this->_trashBagSize];
	for (; i < this->_trashBagSize - 1; i++)
		newTrashBag[i] = this->_trashBag[i];
	newTrashBag[i] = toDrop;
	delete[] this->_trashBag;
	this->_trashBag = newTrashBag;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Wrong index, only 4 materia slot are available : (0 to 3) index only" << std::endl;
		return;
	}
	if (this->_invMateria[idx])
	{
		this->_invMateria[idx]->use(target);
		return;
	}
	std::cout << "Materia slot choosen is empty, add new one with \"equip\" action" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

AMateria *Character::getMateria(int index)
{
	return (this->_invMateria[index]);
}

std::string const &Character::getName() const
{
	return (this->_name);
}

/* ************************************************************************** */

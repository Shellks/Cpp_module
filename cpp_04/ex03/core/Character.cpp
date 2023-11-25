/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:08:52 by acarlott          #+#    #+#             */
/*   Updated: 2023/11/25 10:59:27 by acarlott         ###   ########lyon.fr   */
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
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Character::~Character()
{
	std::cout << this->_name << " has been destroyed by evil forces !" << std::endl;
	int i = 0;
	for (; i < 4; i++)
		if (this->_invMateria[i])
			delete _invMateria[i];
	for (i = 0; i < this->_trashBagSize; i++)
		if (this->_trashBag[i])
			delete _trashBag[i];
	delete[] this->_trashBag;
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
			this->_invMateria[i] = src._invMateria[i];
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
	for (; i < 4; i++)
	{
		if (!this->_invMateria[i])
		{
			this->_invMateria[i] = m;
			std::cout << m->getType() << " materia succesfully added to your materia inventory slot : " << i << std::endl;
			return;
		}
	}
	std::cout << "Materia inventory is full" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 4)
		std::cout << "Wrong index \"0 to 3\", only 4 materia slot are available" << std::endl;
	if (idx < 4 && this->_invMateria[idx])
	{
		this->dropMateria(this->_invMateria[idx]);
		std::cout << "Materia " << this->_invMateria[idx]->getType() << "has been drop" << std::endl;
		this->_invMateria[idx] = NULL;
		return;
	}
	std::cout << "Materia slot are all empty, add new one with \"equip\" action" << std::endl;
}

void Character::dropMateria(AMateria *toDrop)
{
	AMateria **newTrashBag;
	int i = 0;

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
	if (idx < 0 || idx > 4)
		std::cout << "Wrong index \"0 to 3\", only 4 materia slot are available" << std::endl;
	if (idx < 4 && this->_invMateria[idx])
	{
		this->_invMateria[idx]->use(target);
		return;
	}
	std::cout << "Materia slot are all empty, add new one with \"equip\" action" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const &Character::getName() const
{
	return (this->_name);
}

/* ************************************************************************** */

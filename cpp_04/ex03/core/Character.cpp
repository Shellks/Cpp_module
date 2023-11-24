/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:08:52 by acarlott          #+#    #+#             */
/*   Updated: 2023/11/24 15:08:53 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Character::Character() {
	std::cout << "A new unknow hero appears !" << std::endl;
}

Character::Character( std::string name ) : _name(name) {
		std::cout << this->_name << " the great hero appears !" << std::endl;
}

Character::Character( const Character & src ) {
	this->_name = src.getName();
	for (int i = 0; i < 4; i++)
		this->invMateria[i] = src.invMateria[i];
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Character::~Character() {
	std::cout << this->_name << " has been destroyed by evil forces !" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Character &	Character::operator=( Character const & src )
{
	if ( this != &src ) {
		this->_name = src.getName();
		for (int i = 0; i < 4; i++)
			this->invMateria[i] = src.invMateria[i];
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Character::equip(AMateria* m) {

}

void Character::unequip(int idx) {

}

void Character::use(int idx, ICharacter& target) {

}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const & Character::getName() const {
	return (this->_name);
}

/* ************************************************************************** */

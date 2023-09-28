/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:06:00 by acarlott          #+#    #+#             */
/*   Updated: 2023/09/28 21:17:40 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
	this->_Weapon = NULL;
	return ;
}

HumanB::~HumanB(void)
{
	return ;
}

void	HumanB::setWeapon(Weapon& club)
{
	this->_Weapon = &club;
	return ;
}

void	HumanB::attack(void) const
{
	if (this->_Weapon)
		std::cout << this->_name << " attacks with their " << this->_Weapon->getType();
	else
		std::cout << this->_name << " Have no weapons ! can't attack..";
	std::cout << std::endl;
}
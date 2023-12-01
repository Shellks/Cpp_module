/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:41:41 by acarlott          #+#    #+#             */
/*   Updated: 2023/12/01 13:51:53 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _Name("Unnamed"), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0)
{
	std::cout << "ClapTrap "<< this->_Name << " default constructor called !" << std::endl;
	return ;
}


ClapTrap::ClapTrap(std::string name) : _Name(name), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0)
{
	std::cout << "ClapTrap "<< this->_Name << " name constructor called !" << std::endl;
	return ;
}

ClapTrap::ClapTrap(ClapTrap const& src)
{
	std::cout << "ClapTrap "<< this->_Name << " copy constructor called !" << std::endl;
	*this = src;
	return ;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap "<< this->_Name << " destructor called !" << std::endl;
	return ;
}

ClapTrap&	ClapTrap::operator=(ClapTrap const& src)
{
	if (this != &src)
	{
		this->_Name = src._Name;
		this->_HitPoints = src._HitPoints;
		this->_EnergyPoints = src._EnergyPoints;
		this->_AttackDamage = src._AttackDamage;
	}
	return (*this);
}

void	ClapTrap::attack(const std::string& target) 
{
	if (this->_HitPoints != 0) {
		if (this->_EnergyPoints == 0) {
			std::cout << "ClapTrap " << this->_Name << " can't attacks, no more energy.." << std::endl;
			return ;
		}
		this->_EnergyPoints--;
		std::cout << "ClapTrap " << this->_Name << " attacks " << target;
		std::cout << ", causing " << this->_AttackDamage << " points of damage !" << std::endl;
		if (this->_EnergyPoints == 0)
			std::cout << "ClapTrap " << this->_Name << " run out of Energy ! " << std::endl;
	}
}

void		ClapTrap::takedamage(unsigned int amount) 
{
	if (this->_EnergyPoints != 0 || this->_HitPoints != 0) {
		std::cout << "ClapTrap " << this->_Name << " take " << amount << " points of damage !" << std::endl;
		if (amount >= this->_HitPoints)
			this->_HitPoints = 0;
		else
			this->_HitPoints -= amount;
		if (this->_HitPoints == 0)
			std::cout << "Claptrap " << this->_Name << " took too much damage and died !" << std::endl;
	}
	return ;
}

void		ClapTrap::berepaired(unsigned int amount) 
{
	if (this->_HitPoints != 0) {
		if (this->_EnergyPoints == 0) {
			std::cout << "ClapTrap " << this->_Name << " cant repairs itself, no more energy !" << std::endl;
			return ;
		}
		else {
			std::cout << "ClapTrap " << this->_Name << " gain " << amount << " health points by repairing itself" << std::endl;
			this->_HitPoints += amount;
		}
		this->_EnergyPoints--;
		if (this->_EnergyPoints == 0)
			std::cout << "ClapTrap " << this->_Name << " run out of Energy ! " << std::endl;
	}
	return ;
}

std::string	ClapTrap::getName(void) const {
	return (this->_Name);
}

unsigned int	ClapTrap::getHitPoints(void) const {
	return (this->_HitPoints);
}

unsigned int	ClapTrap::getEnergyPoints(void) const {
	return (this->_EnergyPoints);
}

unsigned int	ClapTrap::getAttackDamage(void) const {
	return (this->_AttackDamage);
}

void	ClapTrap::setAttackDamage(unsigned int amount) {
	this->_AttackDamage = amount;
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 20:05:50 by acarlott          #+#    #+#             */
/*   Updated: 2023/10/06 16:21:48 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap() {
	this->_Name = "Unnamed";
	this->_AttackDamage = 20;
	this->_EnergyPoints = 50;
	this->_HitPoints = 100;
	std::cout << "ScavTrap " << this->_Name << " default constructor called !" << std::endl;
	return ;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->_AttackDamage = 20;
	this->_EnergyPoints = 50;
	this->_HitPoints = 100;
	std::cout << "ScavTrap " << this->_Name << " name constructor called !" << std::endl;
	return ;
}

ScavTrap::ScavTrap(ScavTrap const& src) : ClapTrap(src) {
	this->_Name = src._Name;
	this->_HitPoints = src._HitPoints;
	this->_EnergyPoints = src._EnergyPoints;
	this->_AttackDamage = src._AttackDamage;
	std::cout << "ScavTrap " << this->_Name << " copy constructor called !" << std::endl;
	return ;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap " << this->_Name << " destructor called !" << std::endl;
	return ;
}

void	ScavTrap::guardGate(void) 
{
	if (this->_HitPoints != 0)
		std::cout << "ScavTrap " << this->getName() << " enters gate keeper mode" << std::endl;
	return ;
}

void	ScavTrap::attack(const std::string& target) 
{
	if (this->_HitPoints != 0) {
		if (this->_EnergyPoints == 0) {
			std::cout << "ScavTrap " << this->_Name << " can't attacks, no more energy.." << std::endl;
			return ;
		}
		this->_EnergyPoints--;
		std::cout << "ScavTrap " << this->_Name << " attacks " << target;
		std::cout << ", causing " << this->_AttackDamage << " points of damage !" << std::endl;
		if (this->_EnergyPoints == 0)
			std::cout << "ScavTrap " << this->_Name << " run out of Energy ! " << std::endl;
	}
}
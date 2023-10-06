/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:34:29 by acarlott          #+#    #+#             */
/*   Updated: 2023/10/06 17:05:43 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/DiamondTrap.hpp"

// DiamondTrap::DiamondTrap(void) : ScavTrap(), FragTrap() {
// 	this->_Name = "Unnamed";
// 	// this->ClapTrap::_Name = "Unnamed" + "_clap_name";
// 	FragTrap::_HitPoints;
// 	ScavTrap::_EnergyPoints;
// 	FragTrap::_AttackDamage;
// 	std::cout << "DiamondTrap " << this->_Name << " default constructor called !" << std::endl;
// 	return ;
// }

DiamondTrap::DiamondTrap(std::string name) : ScavTrap(name), FragTrap(name) {
	FragTrap::_HitPoints;
	ScavTrap::_EnergyPoints;
	FragTrap::_AttackDamage;
	std::cout << "DiamondTrap " << this->_Name << " name constructor called !" << std::endl;
	return ;
}

// DiamondTrap::DiamondTrap(FragTrap const& src) : ClapTrap(src) {
// 	this->_Name = src._Name;
// 	this->_HitPoints = src._HitPoints;
// 	this->_EnergyPoints = src._EnergyPoints;
// 	this->_AttackDamage = src._AttackDamage;
// 	std::cout << "FragTrap " << this->_Name << " copy constructor called !" << std::endl;
// 	return ;
// }

DiamondTrap::~DiamondTrap(void) {
	std::cout << "DiamondTrap " << this->_Name << " destructor called !" << std::endl;
	return ;
}
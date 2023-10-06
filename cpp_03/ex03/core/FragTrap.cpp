/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:36:12 by acarlott          #+#    #+#             */
/*   Updated: 2023/10/06 16:17:50 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "../include/FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap() {
	this->_Name = "Unnamed";
	this->_AttackDamage = 30;
	this->_EnergyPoints = 100;
	this->_HitPoints = 100;
	std::cout << "FragTrap " << this->_Name << " default constructor called !" << std::endl;
	return ;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->_AttackDamage = 30;
	this->_EnergyPoints = 100;
	this->_HitPoints = 100;
	std::cout << "FragTrap " << this->_Name << " name constructor called !" << std::endl;
	return ;
}

FragTrap::FragTrap(FragTrap const& src) : ClapTrap(src) {
	this->_Name = src._Name;
	this->_HitPoints = src._HitPoints;
	this->_EnergyPoints = src._EnergyPoints;
	this->_AttackDamage = src._AttackDamage;
	std::cout << "FragTrap " << this->_Name << " copy constructor called !" << std::endl;
	return ;
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap " << this->_Name << " destructor called !" << std::endl;
	return ;
}

void	FragTrap::highFivesGuys(void)
{
	std::string	input;

	if (this->_HitPoints != 0) {
		std::cout << "FragTrap " << this->_Name << " want a high fives !" << std::endl;
		std::cout << "do you agree ? (Y/N)" << std::endl;
		std::cout << "> ";
		while (std::getline(std::cin, input)) {
			if (!input.compare("Y") || !input.compare("N")) {
				if (input.compare("Y") == 0) {
					std::cout << "You High fives " << this->_Name << " !" << std::endl;
					break ;
				}
				else {
					std::cout << "You refused the high fives ! " << this->_Name << " is upset.." << std::endl;
					break ;
				}
			}
			else {
				std::cout << "Wrong answer, press 'Y'(yes) or 'N'(no) to make a decision" << std::endl;
				std::cout << std::endl;
				std::cout << "> ";
				continue ;
			}
		}
	}
}
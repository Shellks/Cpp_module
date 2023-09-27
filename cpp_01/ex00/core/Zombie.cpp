/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 11:03:56 by acarlott          #+#    #+#             */
/*   Updated: 2023/09/27 21:09:38 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie::Zombie(std::string name) 
{
	this->_name = name;
	return ;
}

Zombie::~Zombie(void) 
{
	std::cout << "Zombie '" << this->_name << "' destroyed !" << std::endl;
	return ;
}

void	Zombie::announce( void ) 
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 21:18:05 by acarlott          #+#    #+#             */
/*   Updated: 2023/11/16 13:14:21 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie::Zombie(void)
{
	return ;
}
Zombie::~Zombie(void)
{
	return ;
}
void	Zombie::announce( void ) 
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;;
}

void	Zombie::setZombieName(std::string name)
{
	this->_name = name;
	return ;
}

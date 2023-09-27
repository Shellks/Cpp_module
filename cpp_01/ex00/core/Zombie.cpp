/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 11:03:56 by acarlott          #+#    #+#             */
/*   Updated: 2023/09/27 14:28:43 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

void	Zombie::announce( void ) {
	std::cout << this->_name << ": >: BraiiiiiiinnnzzzZ...";
}

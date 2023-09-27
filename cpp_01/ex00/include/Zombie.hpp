/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 11:03:30 by acarlott          #+#    #+#             */
/*   Updated: 2023/09/27 14:31:59 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

# include <iostream>

class Zombie {
	
public:
	Zombie(void);
	~Zombie(void);
	
	void	announce( void );
	void	randomChump( std::string name );
	Zombie*	newZombie( std::string name );
	
private:
	std::string	_name;
	
};

#endif

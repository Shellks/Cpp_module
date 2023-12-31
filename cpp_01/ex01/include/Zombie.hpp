/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 21:12:41 by acarlott          #+#    #+#             */
/*   Updated: 2023/11/17 09:11:32 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

# include <iostream>

class Zombie 
{
private:
	std::string	_name;
public:
	Zombie(void);
	~Zombie(void);
	
	void	announce( void );
	void	setZombieName(std::string name);
};

Zombie*	zombieHorde( int N, std::string name );

#endif
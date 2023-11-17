/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 11:03:30 by acarlott          #+#    #+#             */
/*   Updated: 2023/11/17 09:11:22 by acarlott         ###   ########lyon.fr   */
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
	Zombie(std::string name);
	~Zombie(void);
	
	void	announce( void );
	
};

Zombie  *newZombie( std::string name );
void	randomChump( std::string name );

#endif

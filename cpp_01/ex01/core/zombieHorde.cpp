/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 21:22:12 by acarlott          #+#    #+#             */
/*   Updated: 2023/09/27 23:43:54 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name )
{
	Zombie	*Horde = new (std::nothrow)Zombie[N];
	if (!Horde)
		return NULL;
	for(int i = 0; i < N; i++)
		Horde[i].setZombieName(name);
	return (Horde);
}
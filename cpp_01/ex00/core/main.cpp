/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 11:03:58 by acarlott          #+#    #+#             */
/*   Updated: 2023/09/27 21:08:50 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

int	main(void) 
{
	Zombie	ZombieStack("Stack");
	Zombie	*ZombieHeap = newZombie("Heap");
	ZombieHeap->announce();
	delete (ZombieHeap);
	randomChump("Random");
	ZombieStack.announce();
	return (0);
}
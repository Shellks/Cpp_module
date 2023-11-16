/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 11:03:58 by acarlott          #+#    #+#             */
/*   Updated: 2023/11/16 14:02:19 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

int	main(int argc, char **argv) 
{
	(void)argv;
	if (argc != 1) {
		std::cout << "No arguments are expected at launch" << std::endl;
		return (1);
	}
	Zombie	ZombieStack("Stack");
	Zombie	*ZombieHeap = newZombie("Heap");
	ZombieHeap->announce();
	delete (ZombieHeap);
	randomChump("Random");
	ZombieStack.announce();
	return (0);
}

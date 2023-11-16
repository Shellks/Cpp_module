/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 21:14:14 by acarlott          #+#    #+#             */
/*   Updated: 2023/11/16 14:03:33 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

int	main(int argc, char **argv)
{
	std::string	name;
	int			N;

	(void)argv;
	if (argc != 1) {
		std::cout << "No arguments are expected at launch" << std::endl;
		return (1);
	}
	name = "Dead Walkers";
	N = 10;
	Zombie	*Horde = zombieHorde(N, name);
	if (!Horde) {
		std::cout << "Allocation failure !" << std::endl;
		return (1);
	}
	for(int i = 0; i < N; i++) {
		Horde[i].announce();
		std::cout << "Adress: " << &Horde[i] << std::endl;
	}
	std::cout << "The Zombie horde has " << N << " Members" << std::endl;
	delete [] Horde;
	return (0);
}

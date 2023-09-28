/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 21:14:14 by acarlott          #+#    #+#             */
/*   Updated: 2023/09/28 17:31:37 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

int	main(void)
{
	std::string	name;
	int			N;

	std::cout << "Give a name for your horde : " << std::flush;
	std::cin >> name;
	if (!std::cin.good() || std::cin.eof())
		return 0;
	std::cout << std::endl;
	std::cout << "How many ? :" << std::flush;
	std::cin >> N;
	if (!std::cin.good() || std::cin.eof())
		return 0;
	if (N < 1)
		return (0);
	Zombie	*Horde = zombieHorde(N, name);
	if (!Horde) 
	{
		std::cout << "Alloc error" << std::endl;
		return (1);
	}
	for(int i = 0; i < N; i++) 
	{
		Horde[i].announce();
		std::cout << "Adress: " << &Horde[i] << std::endl;
	}
	delete [] Horde;
	return (0);
}

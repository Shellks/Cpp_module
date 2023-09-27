/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 11:03:58 by acarlott          #+#    #+#             */
/*   Updated: 2023/09/27 14:24:34 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

int	main(void) {
	Zombie	ZombieHeap;
	Zombie	*Zombiestack;
	std::string	name;

	std::cout << "Enter your zombie name : ";
	std:: cin >> name;
	Zombiestack = new Zombie(name);
	delete (Zombiestack);
	return (0);
}

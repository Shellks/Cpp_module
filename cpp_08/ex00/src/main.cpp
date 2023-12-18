/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:18:42 by acarlott          #+#    #+#             */
/*   Updated: 2023/12/18 21:58:27 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/easyfind.hpp"

int main(void) 
{
	{
		try
		{
			unsigned int to_find = 9;
			std::vector<int> intContainers;

			intContainers.push_back(42);
			intContainers.push_back(12);
			intContainers.push_back(21);
			intContainers.push_back(7);
			
			std::cout << YELLOW << "Search " << CYAN << to_find << YELLOW << " in the container.." << RESET << std::endl;
			easyfind(intContainers, to_find);
		}
		catch (std::exception const &e)
		{
			std::cout << " - " << RED << "Error: " << e.what() << RESET << std::endl;
		}
		
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 10:55:28 by acarlott          #+#    #+#             */
/*   Updated: 2023/11/09 14:57:54 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"

int	main(void)
{
	PhoneBook repertory;
	std::string	buf;

	std::cout << "> ";
	while(std::getline(std::cin, buf)) {
		if (buf.compare("ADD") == 0) 
			repertory.addcontact();
		else if (buf.compare("SEARCH") == 0)
			repertory.searchcontact();
		else if (buf.compare("EXIT") == 0)
			break ;
		else
			std::cout << "Unknow request, please read the notice forward" << std::endl;
		std::cout << std::endl << "> ";
	}
	return 0;
}

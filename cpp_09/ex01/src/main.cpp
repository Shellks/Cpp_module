/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:24:28 by acarlott          #+#    #+#             */
/*   Updated: 2024/01/06 13:21:20 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"

int main(int argc, char **argv)
{
	
	if (argc != 2) {
		std::cout << RED << "ERROR:" << BLUE << " only one argument expected \"./RPN 'RPN calcul'\"" << RESET << std::endl;
		return (1);
	}
	try {
		int result = RPNCalculator(argv[1]);
		std::cout << YELLOW << "The result of the RPN calculation is : " << CYAN << result << RESET << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << RED << PREFIX_ERROR << e.what() << RESET << std::endl;
		return (0);
	}
	return (1);
}
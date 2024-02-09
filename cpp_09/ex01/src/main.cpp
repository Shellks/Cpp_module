/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:24:28 by acarlott          #+#    #+#             */
/*   Updated: 2024/02/09 10:18:04 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"

int main(int argc, char **argv)
{
	
	if (argc != 2) {
		std::cout << RED << PREFIX_ERROR << RESET << " only one argument expected \"./RPN 'RPN calcul'\"" << std::endl;
		return (1);
	}
	try {
		int result = RPNCalculator(argv[1]);
		std::cout << result << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << RED << PREFIX_ERROR << RESET << e.what() << std::endl;
		return (1);
	}
	return (0);
}

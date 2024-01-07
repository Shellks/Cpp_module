/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:24:28 by acarlott          #+#    #+#             */
/*   Updated: 2024/01/07 09:52:45 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc == 1) {
		std::cout << RED << PREFIX_ERROR << RESET << "expected argument \"./PmergeMe 'integers'... \"" << std::endl;
		return (1);
	}
	try {
		PmergeMe	sequence(&argv[1]);
	}
	catch (const std::exception &e) {
		std::cout << RED << PREFIX_ERROR << e.what() << RESET << std::endl;
		return (1);
	}
	return (0);
}
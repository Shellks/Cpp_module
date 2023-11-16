/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:22:41 by acarlott          #+#    #+#             */
/*   Updated: 2023/11/16 14:27:03 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Harl.hpp"

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 1) {
		std::cout << "No arguments are expected at launch" << std::endl;
		return (1);
	}
	Harl	Harlcomplain;

	std::cout << std::endl;
	Harlcomplain.complain("debug");
	std::cout << "-----------------" << std::endl;
	Harlcomplain.complain("info");
	std::cout << "-----------------" << std::endl;
	Harlcomplain.complain("warning");
	std::cout << "-----------------" << std::endl;
	Harlcomplain.complain("error");
	std::cout << std::endl;
	return 0;
}

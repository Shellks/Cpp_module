/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:22:41 by acarlott          #+#    #+#             */
/*   Updated: 2023/09/29 14:51:50 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Harl.hpp"

int	main(int argc, char **argv)
{
	Harl	Harlcomplain;

	if (argc != 2) {
		std::cout << "Wrong numbers of parameters, only one expected" << std::endl;
		return 1;
	}
	Harlcomplain.complain((std::string)argv[1]);
	return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:22:41 by acarlott          #+#    #+#             */
/*   Updated: 2023/09/29 14:41:59 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Harl.hpp"

int	main(void)
{
	Harl	Harlcomplain;

	std::cout << "-----------------" << std::endl;
	Harlcomplain.complain("debug");
	std::cout << "-----------------" << std::endl;
	Harlcomplain.complain("info");
	std::cout << "-----------------" << std::endl;
	Harlcomplain.complain("warning");
	std::cout << "-----------------" << std::endl;
	Harlcomplain.complain("error");
	std::cout << "-----------------" << std::endl;
	return 0;
}
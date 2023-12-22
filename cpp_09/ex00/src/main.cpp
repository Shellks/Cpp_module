/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:24:28 by acarlott          #+#    #+#             */
/*   Updated: 2023/12/21 19:33:03 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
	{
		std::cout << RED << "ERROR:" << BLUE << " only one argument expected './btc *.txt'" << RESET << std::endl;
		return (1);
	}
	BitcoinExchange	test;
	test.btcParser(argv[1]);
}
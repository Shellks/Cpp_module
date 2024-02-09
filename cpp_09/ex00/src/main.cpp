/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:24:28 by acarlott          #+#    #+#             */
/*   Updated: 2024/02/09 11:53:14 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout << RED << "ERROR:" << RESET << " only one argument expected './btc *.txt'" << std::endl;
		return (1);
	}
	char	data[] = "data.csv";
	BitcoinExchange	test;
	try {
		test.btcParser(argv[1], data);
	}
	catch(const std::exception& e) {
		std::cerr << RED << "Error: " << RESET << e.what() << std::endl;
	}
}

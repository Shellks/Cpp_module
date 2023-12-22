/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:25:52 by acarlott          #+#    #+#             */
/*   Updated: 2023/12/22 10:07:59 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src)
{
	(void)src;
}

BitcoinExchange::~BitcoinExchange()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &src)
{
	(void)src;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	BitcoinExchange::_parseDbCsv()
{
	std::ifstream	fileStream(this->_fileCsv);
	std::string	buffer;
	std::string	date;
	std::string	value;

	if (std::getline(fileStream, buffer, '\0')) {
		std::stringstream	strStream(buffer);
		while (std::getline(strStream, date, ',') && std::getline(strStream, value, '\n'))
			this->_dataCsv.insert(std::make_pair(date, std::atof(value.c_str())));
		for (iterator it = this->_dataCsv.begin(); it != this->_dataCsv.end(); it++) {
			std::cout << "Clé: " << it->first << " Valeur: " << it->second << std::endl;
		}
		this->_dataCsv.erase(this->_dataCsv.end());
	}
	else
	{
		fileStream.close();
		throw(BitcoinExchange::EmptyFileException());
	}
	fileStream.close();
}

void	BitcoinExchange::_parseDbUser()
{

}

void	BitcoinExchange::btcParser(char *file)
{
	try {
		std::ifstream	fileStream(file);
		if (!fileStream.is_open())
			throw(BitcoinExchange::FileNotExistException());
		fileStream.close();
		this->_fileCsv = const_cast<const char *>(file);
		this->_parseDbCsv();
		//this->_parseDbUser();
	}
	catch(const std::exception& e) {
		std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
	}
	
}
/*
** --------------------------------- EXCEPTION ----------------------------------
*/

const char *BitcoinExchange::FileNotExistException::what(void) const throw()
{
	return ("Invalid File");
}

const char *BitcoinExchange::EmptyFileException::what(void) const throw()
{
	return ("Empty File");
}
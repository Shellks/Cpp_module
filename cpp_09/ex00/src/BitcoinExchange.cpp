/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:25:52 by acarlott          #+#    #+#             */
/*   Updated: 2023/12/22 14:34:13 by acarlott         ###   ########lyon.fr   */
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
	std::string	path = "ressource/data.csv";
	std::string	date;
	std::string	value;
	std::string	buffer;
	std::ifstream	fileStream(path.c_str());

	if (!fileStream.is_open())
		throw(BitcoinExchange::FileNotExistException());
	else if (std::getline(fileStream, buffer, '\0')) {
		std::stringstream	strStream(buffer);
		while (std::getline(strStream, date, ',') && std::getline(strStream, value, '\n')) {
			if (!date.compare("date"))
				continue;
			else if (date.find_first_not_of("0123456789-") == std::string::npos && value.find_first_not_of("0123456789.")  == std::string::npos)
				this->_dataCsv.insert(std::make_pair(date, std::atof(value.c_str())));
			else
				throw (BitcoinExchange::BadFileException());
		}
		for (iterator it = this->_dataCsv.begin(); it != this->_dataCsv.end(); it++) {
			
			std::cout << YELLOW << "Clé: " << CYAN << it->first << YELLOW << " Valeur: " << CYAN << it->second << RESET << std::endl;
		}
		std::cout << MAGENTA << "********************************" << RESET << std::endl;
	}
	else
	{
		fileStream.close();
		throw(BitcoinExchange::EmptyFileException());
	}
	fileStream.close();
}

bool	BitcoinExchange::_isValideDate(std::string const &date)
{
	if (date.size() != 10)
		return (false);
	if (date[4] != '-' || date[7] != '-')
		return (false);
	for (int i = 0; i < date.size(); i++) {
		if (i != 4 && i != 7 && !std::isdigit(date[i]))
			return (false);
	}
	return (true);
}

std::string	BitcoinExchange::_trimParser(std::string toTrim)
{
	size_t trim_start = toTrim.find_first_not_of(" ");
	if (trim_start == std::string::npos)
		throw(BitcoinExchange::EmptyFileException());
	size_t trim_end = toTrim.find_last_not_of(" ");
	toTrim = toTrim.substr(trim_start);
	toTrim = toTrim.substr(0, trim_end + 1);
	return (toTrim);
}

void	BitcoinExchange::_parseDbUser(const char *file)
{
	std::string	date;
	std::string	amount;
	std::string	buffer;
	std::ifstream	fileStream(file);
	
	if (!fileStream.is_open())
		throw(BitcoinExchange::FileNotExistException());
	else if (std::getline(fileStream, buffer, '\0')) {
		std::stringstream	strStream(buffer);
		while (std::getline(strStream, date, '|') && std::getline(strStream, amount, '\n')) {
			date = this->_trimParser(date);
			amount = this->_trimParser(amount);
			if (this->_isValideDate(date) == false || std::atof(amount.c_str()) < 0 || std::atof(amount.c_str()) > 1000)
				throw (BitcoinExchange::BadFileException());
			if (date.find_first_not_of("0123456789-") == std::string::npos && amount.find_first_not_of("0123456789.")  == std::string::npos)
				this->_dataUser.insert(std::make_pair(date, std::atof(amount.c_str())));
			else
				throw (BitcoinExchange::BadFileException());
		}
		for (iterator it = this->_dataUser.begin(); it != this->_dataUser.end(); it++) {
				std::cout << YELLOW << "Date: " << CYAN << it->first << YELLOW << " Amount: " << CYAN << it->second << RESET << std::endl;
		}
		std::cout << MAGENTA << "********************************" << RESET << std::endl;
	fileStream.close();
	}
	else {
		fileStream.close();
		throw(BitcoinExchange::EmptyFileException());
	}
}

void	BitcoinExchange::btcParser(char *file)
{
	try {
		this->_parseDbUser(file);
		//this->_parseDbCsv();
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

const char *BitcoinExchange::BadFileException::what(void) const throw()
{
	return ("Bad File format");
}

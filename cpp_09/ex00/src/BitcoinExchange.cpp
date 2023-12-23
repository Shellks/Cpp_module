/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:25:52 by acarlott          #+#    #+#             */
/*   Updated: 2023/12/23 10:24:52 by acarlott         ###   ########lyon.fr   */
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

void	BitcoinExchange::_printBtcValue(void)
{
	float result;
	
	for (iterator it1 = this->_dataUser.begin(); it1 != this->_dataUser.end(); it1++) {
		// if (this->_isValidInput(it1.first, it1->second) == false)
		iterator it2 = this->_dataCsv.find(it1->first);
		if (it2 != this->_dataCsv.end()) {
			result = it1->second * it2->second;
			std::cout << CYAN << it1->first << RESET << " => " << CYAN << it1->second << RESET << " = " << CYAN << result << RESET << std::endl;
		}
		else {
			iterator itlower = this->_dataCsv.lower_bound(it1->first);
			if (itlower != this->_dataCsv.begin()) {
				--itlower;
			result = it1->second * itlower->second;
			std::cout << CYAN << it1->first << RESET << " => " << CYAN << it1->second << RESET << " = " << CYAN << result << RESET << std::endl;
			}
		}
	}
}

void	BitcoinExchange::btcParser(char *file)
{
	try {
		this->_parseDbUser(file);
		this->_parseDbCsv();
		this->_printBtcValue();
	}
	catch(const std::exception& e) {
		std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
	}
	
}

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
	}
	else
	{
		fileStream.close();
		throw(BitcoinExchange::EmptyFileException());
	}
	fileStream.close();
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
			// if (this->_isValidInput(date, amount) == false)
			// 	throw (BitcoinExchange::BadFileException());
			this->_dataUser.insert(std::make_pair(date, std::atof(amount.c_str())));
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

bool	BitcoinExchange::_isValidInput(std::string const &date, std::string const &amount)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-' || \
	std::atof(date.c_str()) > 2024 || std::atof(date.c_str()) < 2009 || \
	std::atof(&date.c_str()[5]) > 12 || std::atof(&date.c_str()[5]) < 1 || \
	std::atof(&date.c_str()[8]) > 31 || std::atof(&date.c_str()[8]) < 1 || \
	(std::atof(date.c_str()) == 2009 && std::atof(&date.c_str()[8]) < 2)) {
		std::cout << RED << "Error: bad input => " << date << RESET << std::endl;
		return (false);
	}
	for (size_t i = 0; i < date.size(); i++) {
		if (i != 4 && i != 7 && !std::isdigit(date[i])) {
			std::cout << RED << "Error: bad input => " << date << RESET << std::endl;
			return (false);
		}
		if (i < amount.size() && !std::isdigit(amount[i]) && amount[i] != '.') {
			std::cout << RED << "Error: bad input => " << amount << RESET << std::endl;
			return (false);
		}
	}
	size_t	count = 0;
	for (size_t i = 0; i < amount.size(); i++) {
		if (i == 0 && amount[i] == '.') {
			std::cout << RED << "Error: bad input => " << amount << RESET << std::endl;
			return (false);
		}
		if (amount[i] == '.')
			count++;
	}
	if (std::atof(amount.c_str()) > 1000) {
		std::cout << RED << "Error: too large number" << amount << RESET << std::endl;
		return (false);
	}
	else if (std::atof(amount.c_str()) < 0) {
		std::cout << RED << "Error: not a positive number" << amount << RESET << std::endl;
		return (false);
	}
	if (count > 1 || std::atof(amount.c_str()) < 0 || std::atof(amount.c_str()) > 1000 || \
		(date.find_first_not_of("0123456789-") != std::string::npos && amount.find_first_not_of("0123456789.")  != std::string::npos)) {
			std::cout << RED << "Error: bad input => " << amount << RESET << std::endl;
			return (false);
		}
	return (true);
}

bool	BitcoinExchange::_isValidInput(std::string const &date, std::string const &amount)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-' || \
	std::atof(date.c_str()) > 2024 || std::atof(date.c_str()) < 2009 || \
	std::atof(&date.c_str()[5]) > 12 || std::atof(&date.c_str()[5]) < 1 || \
	std::atof(&date.c_str()[8]) > 31 || std::atof(&date.c_str()[8]) < 1 || \
	(std::atof(date.c_str()) == 2009 && std::atof(&date.c_str()[8]) < 2))
		return (false);
	for (size_t i = 0; i < date.size(); i++) {
		if (i != 4 && i != 7 && !std::isdigit(date[i]))
			return (false);
		if (i < amount.size() && !std::isdigit(amount[i]) && amount[i] != '.')
			return (false);
	}
	size_t	count = 0;
	for (size_t i = 0; i < amount.size(); i++) {
		if (i == 0 && amount[i] == '.')
			return (false);
		if (amount[i] == '.')
			count++;
	}
	if (count > 1 || std::atof(amount.c_str()) < 0 || std::atof(amount.c_str()) > 1000 || \
		(date.find_first_not_of("0123456789-") != std::string::npos && amount.find_first_not_of("0123456789.")  != std::string::npos))
		return (false);
	return (true);
}


/*
** --------------------------------- EXCEPTION ----------------------------------
*/

const char *BitcoinExchange::FileNotExistException::what(void) const throw()
{
	return ("Invalid file");
}

const char *BitcoinExchange::EmptyFileException::what(void) const throw()
{
	return ("Empty file");
}

const char *BitcoinExchange::BadFileException::what(void) const throw()
{
	return ("Bad file format: \"date | amount\"\n-date: \"Year-Month-Day\"\n-amount: \"int/float\"");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:25:52 by acarlott          #+#    #+#             */
/*   Updated: 2024/01/05 16:26:21 by acarlott         ###   ########lyon.fr   */
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

void	BitcoinExchange::btcParser(char *file)
{
	try {
		this->_parseDbCsv();
		this->_parseDbUser(file);
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
				this->_data.insert(std::make_pair(date, std::atof(value.c_str())));
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
	std::string	line;
	std::ifstream	fileStream(file);
	
	if (!fileStream.is_open() || fileStream.peek() == std::ifstream::traits_type::eof()) {
		fileStream.close();
		throw(BitcoinExchange::FileNotExistException());
	}
	while (std::getline(fileStream, line)) {
		std::stringstream	strStream(line);
		if (std::getline(strStream, date, '|') && std::getline(strStream, amount, '\n')) {
			if (!date.compare("date "))
				continue;
			date = this->_trimParser(date);
			amount = this->_trimParser(amount);
			this->_printBtcValue(date, amount);
		}
		else {
			date = this->_trimParser(date);
			this->_printBtcValue(date, "null");
		}
	}
	fileStream.close();
}

void	BitcoinExchange::_printBtcValue(std::string const date, std::string const amount)
{
	float result;
	
	if (this->_isValidInput(date, amount) == false)
		return;
	iterator it2 = this->_data.find(date);
	if (it2 != this->_data.end()) {
		result = std::atof(amount.c_str()) * it2->second;
		std::cout << date << " => " << amount <<  " = " << result << std::endl;
	}
	else {
		iterator itlower = this->_data.lower_bound(date);
		if (itlower != this->_data.begin()) {
			--itlower;
			result = std::atof(amount.c_str()) * itlower->second;
			std::cout << date << " => " << amount <<  " = " << result << std::endl;
		}
		else {
			iterator itupper = this->_data.upper_bound(date);
			result = std::atof(amount.c_str()) * itupper->second;
			std::cout << date << " => " << amount <<  " = " << result << std::endl;
		}
	}
}

bool	BitcoinExchange::_isValidInput(std::string const &date, std::string const &amount)
{
	if (!amount.compare("null")) {
		std::cout << "Error: bad input => " << date << std::endl;
		return (false);
	}
	if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
		std::cout << "Error: bad input => " << date << " | " << amount << std::endl;
		return (false);
	}
	for (size_t i = 0; i < date.size(); i++) {
		if (i != 4 && i != 7 && !std::isdigit(date[i])) {
			std::cout << "Error: bad input => " << date << " | " << amount << std::endl;
			return (false);
		}
	}
	size_t	count = 0;
	for (size_t i = 0; i < amount.size(); i++) {
		if (amount[i] == '.')
			count++;
		if ((i == 0 && amount[i] == '.') || count > 1 || \
		(!std::isdigit(amount[i]) && amount[i] != '.' && amount[i] != '-')) {
			std::cout << "Error: bad input => " << date << " | " << amount << std::endl;
			return (false);
		}
	}
	if (std::atof(amount.c_str()) < 0) {
		std::cout <<"Error: not a positive number." << std::endl;
		return (false);
	}
	else if (std::atof(amount.c_str()) > 1000) {
		std::cout <<"Error: too large a number." << std::endl;
		return (false);
	}
	return (true);
}

std::string	BitcoinExchange::_trimParser(std::string toTrim)
{
	size_t trim_end;
	size_t trim_start = toTrim.find_first_not_of(" ");
	if (trim_start == std::string::npos)
		return (toTrim);
	if (toTrim.find('\n') != std::string::npos)
		trim_end = toTrim.find('\n');
	else
		trim_end = toTrim.find_last_not_of(" ");
	toTrim = toTrim.substr(trim_start);
	toTrim = toTrim.substr(0, trim_end + 1);
	return (toTrim);
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

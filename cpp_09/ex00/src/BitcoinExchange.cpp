/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:25:52 by acarlott          #+#    #+#             */
/*   Updated: 2024/02/09 09:10:04 by acarlott         ###   ########lyon.fr   */
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
	std::string		path = "ressource/data.csv";
	std::string		date;
	std::string		value;
	std::string		buffer;
	std::ifstream	fileStream(path.c_str());
	size_t			count = 0;

	if (!fileStream.is_open())
		throw(std::invalid_argument("data file does not exist or has a forbidden permission"));
	else if (std::getline(fileStream, buffer, '\0')) {
		std::stringstream	strStream(buffer);
		while (std::getline(strStream, date, ',') && std::getline(strStream, value, '\n')) {
			count++;
			if (count == 1) {
				if (date.compare("date") || value.compare("exchange_rate"))
					throw (std::invalid_argument("csv headers must be \"date,exchange_rate\""));
				else
					continue;
			}
			if (value.empty() || value.find('-') != std::string::npos) 
				throw (BitcoinExchange::BadFileException());
			if (this->_isValidDate(date) == false || this->_isValidValue(value) == false)
				throw (BitcoinExchange::BadFileException());
			this->_data.insert(std::make_pair(date, std::atof(value.c_str())));
		}
	}
	else {
		fileStream.close();
		throw(std::invalid_argument("data file is empty"));
	}
	if (count < 2)
		throw(std::invalid_argument("Need one or more data in data file"));
	fileStream.close(); 
}

void	BitcoinExchange::_parseDbUser(const char *file)
{
	std::string	date;
	std::string	amount;
	std::string	line;
	std::ifstream	fileStream(file);
	
	if (!fileStream.is_open()) {
		fileStream.close();
		throw(std::invalid_argument("input file does not exist or has a forbidden permission"));
	}
	size_t	count = 0;
	while (std::getline(fileStream, line)) {
		count++;
		if (line.size() == 1 && line[0] == '|') {
			std::cout << "Error: bad input => " << line << std::endl;
			continue ;
		}
		std::stringstream	strStream(line);
		if (std::getline(strStream, date, '|') && std::getline(strStream, amount, '\n')) {
			date = this->_trimParser(date);
			amount = this->_trimParser(amount);
			if (count == 1 && !date.compare("date") && !amount.compare("value"))
				continue;
			this->_printBtcValue(date, amount);
		}
		else {
			if (!date.empty()) {
				date = this->_trimParser(date);
				this->_printBtcValue(date, "null");
			}
		}
	}
	fileStream.close();
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
		return false;
	}
	if (this->_isValidValue(amount) == false || this->_isValidDate(date) == false) {
		std::cout << "Error: bad input => " << date << " | " << amount << std::endl;
		return false;
	}
	if (std::atof(amount.c_str()) < 0) {
		std::cout <<"Error: not a positive number." << std::endl;
		return false;
	}
	else if (std::atof(amount.c_str()) > 1000) {
		std::cout <<"Error: too large a number." << std::endl;
		return false;
	}
	return true;
}

bool	BitcoinExchange::_isValidValue(std::string const &value)
{
	if (value.find_first_not_of("0123456789.-f")  != std::string::npos)
		return false;
	size_t	count = 0;
	for (size_t i = 0; i < value.size(); i++) {
		switch (value[i]) {
			case '-':
				if ( i != 0 || value.size() == 1 || !std::isdigit(value[i + 1]))
					return false;
				break;
			case 'f':
				if ( i + 1 != value.size() || value.size() == 1 || !std::isdigit(value[i - 1]))
					return false;
				break;
			case '.':
				if (i + 1 == value.size() || i == 0 || count > 0)
					return false;
				count++;
				break;
		}
	}
	return true;
}

bool	BitcoinExchange::_isValidDate(std::string const &date)
{
	bool	leapYear;
	char	delimiter;
	int		year;
	int		month;
	int		day;
	
	if (date.find_first_not_of("0123456789-") != std::string::npos)
		return false;
	if (date.size() != 10 || date[4] != '-' || date[7] != '-' )
		return false;
	std::istringstream	iss(date);
	iss >> year >> delimiter >> month >> delimiter >> day;
	if (year < 0001 || year > 9999 || month < 1 || month > 12 || day < 1)
		return (false);
	(year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) ? leapYear = true : leapYear = false;
	if (month == 2) {
		if (leapYear == false && day > 28)
			return false;
		else if (leapYear == true && day > 29)
			return false;
	}
	else {
		if ((month <= 7 && month % 2 == 1) || (month >= 8 && month % 2 == 0)) {
			if (day > 31)
				return false;
		}
		else {
			if (day > 30)
				return false;
		}
	}
	return (true);
}

/*
** --------------------------------- EXCEPTION ----------------------------------
*/

const char *BitcoinExchange::BadFileException::what(void) const throw()
{
	return ("Bad data file format: \"date, exchange_rate\"\n-date: \"Year-Month-Day\"\n-exchange_rate: \"int/float\"");
}

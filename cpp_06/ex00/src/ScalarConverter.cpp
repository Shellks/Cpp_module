/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:01:26 by acarlott          #+#    #+#             */
/*   Updated: 2023/12/14 23:08:01 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	// std::cout << "ScalarConverter " << YELLOW << this->_name << RESET << " was " << GREEN << "created" << RESET << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
	(void)src;
	// std::cout << "ScalarConverter " << YELLOW << this->_name << RESET << " was " << GREEN << "creat " << RESET << "with " << YELLOW << src._name << RESET << " ScalarConverter" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	// std::cout << "ScalarConverter " << YELLOW << this->_name << RESET << " was " << RED "fired" << RESET << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &src)
{
	(void)src;
	return *this;
}
/*
** --------------------------------- METHODS ----------------------------------
*/
void ScalarConverter::convert(std::string const &litteralString)
{
	if (litteralString.find_first_not_of("0123456789.-+inaf") != std::string::npos)
	{
		std::cout << RED << "Error: invalid parameters" << std::endl;
		return;
	}
	bool isExist = false;
	std::string tab[7] = {"-inff", "-inf", "+inff", "+inf", "nanf", "nan", "-inf"};
	if (litteralString.find_first_of("ain") != std::string::npos)
	{
		for (int i = 0; i < 7; i++)
			if (!litteralString.compare(tab[i]))
				isExist = true;
		if (isExist == false)
		{
			std::cout << RED << "Error: invalid parameters" << std::endl;
			return;
		}
	}
	//LE IF HASARDEUX RIP
	if (litteralString.find_first_of("f") != std::string::npos && litteralString.size() != (litteralString.find_first_of("f") + 1) &&
		(litteralString[litteralString.find_first_of("f") - 1] == '.' || std::isdigit(litteralString[litteralString.find_first_of("f") - 1])))
	{
		std::cout << RED << "Error: invalid parameters" << std::endl;
		return;
	}
	char *endptr;
	double litteralDouble = strtod(litteralString.c_str(), &endptr);
	std::cout << YELLOW << "Convert" << RESET << " | " << YELLOW << "litteral string " << RESET << "\"" << BLUE << litteralString << RESET << "\"" << std::endl;
	ConvertToChar(litteralDouble);
	ConvertToInt(litteralDouble);
	ConvertToFloat(litteralDouble);
	ConvertToDouble(litteralDouble);
}

void ScalarConverter::ConvertToInt(double const litteralDouble)
{
	if (litteralDouble != litteralDouble || litteralDouble >= std::numeric_limits<int>::max() || litteralDouble <= std::numeric_limits<int>::min())
	{
		std::cout << "        |  -" << MAGENTA << " int    " << RESET << ": " << BLUE << "impossible" << RESET << std::endl;
		return;
	}
	std::cout << "        |  -" << MAGENTA << " int    " << RESET << ": " << BLUE << static_cast<int>(litteralDouble) << RESET << std::endl;
}
void ScalarConverter::ConvertToFloat(double const litteralDouble)
{
	if (litteralDouble == 0)
	{
		std::cout << "        |  -" << MAGENTA << " float  " << RESET << ": " << BLUE << static_cast<float>(litteralDouble) << ".0f" << RESET << std::endl;
		return;
	}

	if (litteralDouble >= std::numeric_limits<float>::max() || litteralDouble <= std::numeric_limits<float>::min())
	{
		if (litteralDouble >= std::numeric_limits<float>::max())
			std::cout << "        |  -" << MAGENTA << " float  " << RESET << ": " << BLUE << "inff" << RESET << std::endl;
		else
			std::cout << "        |  -" << MAGENTA << " float  " << RESET << ": " << BLUE << "-inff" << RESET << std::endl;
		return;
	}
	int checkDecimal = static_cast<int>(litteralDouble);
	if (litteralDouble < 999999 && litteralDouble > -999999)
	{
		if (static_cast<double>(checkDecimal) == litteralDouble)
			std::cout << "        |  -" << MAGENTA << " float  " << RESET << ": " << BLUE << static_cast<float>(litteralDouble) << ".0f" << RESET << std::endl;
		else
			std::cout << "        |  -" << MAGENTA << " float  " << RESET << ": " << BLUE << static_cast<float>(litteralDouble) << "f" << RESET << std::endl;
	}
	else
		std::cout << "        |  -" << MAGENTA << " float  " << RESET << ": " << BLUE << static_cast<float>(litteralDouble) << "f" << RESET << std::endl;
}
void ScalarConverter::ConvertToChar(double const litteralDouble)
{
	if (static_cast<int>(litteralDouble) >= 0 && static_cast<int>(litteralDouble) <= 128)
	{
		if (std::isprint(static_cast<char>(litteralDouble)))
			std::cout << "        |  -" << MAGENTA << " char   " << RESET << ": " << BLUE << static_cast<char>(litteralDouble) << RESET << std::endl;
		else
			std::cout << "        |  -" << MAGENTA << " char   " << RESET << ": " << BLUE << "Non displayable" << RESET << std::endl;
		return;
	}
	else
		std::cout << "        |  -" << MAGENTA << " char   " << RESET << ": " << BLUE << "impossible" << RESET << std::endl;
}

void ScalarConverter::ConvertToDouble(double const litteralDouble)
{
	int checkDecimal = static_cast<int>(litteralDouble);
	if (static_cast<double>(checkDecimal) == litteralDouble && litteralDouble < 999999 && litteralDouble > -999999)
		std::cout << "        |  -" << MAGENTA << " Double " << RESET << ": " << BLUE << static_cast<double>(litteralDouble) << ".0" << RESET << std::endl;
	else
		std::cout << "        |  -" << MAGENTA << " Double " << RESET << ": " << BLUE << static_cast<double>(litteralDouble) << RESET << std::endl;
}

/*
** --------------------------------- EXCEPTION ----------------------------------
*/

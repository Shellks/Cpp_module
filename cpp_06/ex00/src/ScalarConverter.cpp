/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:01:26 by acarlott          #+#    #+#             */
/*   Updated: 2023/12/15 14:15:55 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
	(void)src;
}

ScalarConverter::~ScalarConverter()
{
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

bool ScalarConverter::ConvertParser(std::string *l_str) 
{
	if (l_str->empty())
		return (false);
	int trim_start = l_str->find_first_not_of(" \t");
	*l_str = l_str->substr(trim_start);
	int trim_end = l_str->find_last_not_of(" \t");
	*l_str = l_str->substr(0, trim_end + 1);
	if (l_str->find_first_not_of("0123456789.-+inaf") != std::string::npos)
		return (false);
	if (l_str->find_first_of("ain") != std::string::npos)
	{
		std::string tab[7] = {"-inff", "-inf", "+inff", "+inf", "nanf", "nan", "-inf"};
		for (int i = 0; i < 7; i++)
		{
			if (!l_str->compare(tab[i]))
				return (true);
			if (i == 6)
				return (false);
		}
	}
	if (l_str->find("f") != std::string::npos) {
		int	point_count = 0;
		int	f_count = 0;
		for (std::string::iterator	it = l_str->begin(); it != l_str->end(); it++) {
			if (*it == '.')
				point_count++;
			if (*it == 'f')
				f_count++;
		}
		if (l_str->size() != (l_str->find("f") + 1) || point_count != 1 || f_count != 1)
			return (false);
	}
	return (true);
}

void ScalarConverter::convert(std::string l_str)
{
	if (ConvertParser(&l_str) == false) {
		std::cout << RED << "Error: invalid parameters" << std::endl;
		return;
	}
	char *endptr;
	double litteralDouble = strtod(l_str.c_str(), &endptr);
	std::cout << YELLOW << "Convert" << RESET << " | " << YELLOW << "litteral string " << RESET << "\"" << BLUE << l_str << RESET << "\"" << std::endl;
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
	if (litteralDouble >= std::numeric_limits<float>::max() || litteralDouble <= std::numeric_limits<float>::min()) {
		if (litteralDouble >= std::numeric_limits<float>::max()) {
			std::cout << "        |  -" << MAGENTA << " float  " << RESET << ": " << BLUE << "inff" << RESET << std::endl;
			return;
		}
		else if (litteralDouble >= std::numeric_limits<float>::min()) {
			std::cout << "        |  -" << MAGENTA << " float  " << RESET << ": " << BLUE << "-inff" << RESET << std::endl;
			return;
		}
	}
	int checkDecimal = static_cast<int>(litteralDouble);
	if (litteralDouble < 999999 && litteralDouble > -999999) {
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
			std::cout << "        |  -" << MAGENTA << " char   " << RESET << ": '" << BLUE << static_cast<char>(litteralDouble) << RESET << "'" << std::endl;
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

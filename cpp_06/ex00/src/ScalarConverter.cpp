/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:01:26 by acarlott          #+#    #+#             */
/*   Updated: 2023/12/21 00:26:26 by acarlott         ###   ########lyon.fr   */
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

bool ScalarConverter::ConvertParser(std::string *l_str, unsigned int *type)
{
	if (l_str->empty())
		return (false);
	std::string::size_type trim_start = l_str->find_first_not_of(" \t");
	if (trim_start == std::string::npos)
	{
		if (l_str->size() > 1)
			return (false);
		else
			return (true);
	}
	std::string::size_type trim_end = l_str->find_last_not_of(" \t");
	*l_str = l_str->substr(trim_start);
	*l_str = l_str->substr(0, trim_end + 1);
	if (l_str->size() == 1 && static_cast<unsigned char>(l_str->at(0)) <= 127 && l_str->find_first_of("0123456789") == std::string::npos)
	{
		*type = CHAR;
		return (true);
	}
	if (l_str->find_first_not_of("0123456789.-+inaf") != std::string::npos)
		return (false);
	if (l_str->find_first_of("ain") != std::string::npos)
	{
		std::string tab[7] = {"-inff", "-inf", "+inff", "+inf", "nanf", "nan"};
		for (int i = 0; i <= 6; i++)
		{
			if (i == 6)
				return (false);
			if (!l_str->compare(tab[i]))
			{
				if (tab[i].compare("-inff") || tab[i].compare("+inff") || tab[i].compare("nanf"))
					*type = FLOAT;
				else
					*type = DOUBLE;
				return (true);
			}
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
		*type = FLOAT;
	}
	if (l_str->find(".") != std::string::npos && l_str->find("f") == std::string::npos)
		*type = DOUBLE;
	else
		*type = INT;
	return (true);
}


void ScalarConverter::convert(std::string l_str)
{
	int	i;
	char	c;
	float	f;
	double	d;
	unsigned int	type;
	if (ConvertParser(&l_str, &type) == false) {
		std::cout << RED << "Error: invalid parameters" << std::endl;
		return;
	}
	switch (type)
	{
	case INT:
		i = std::atoi(l_str.c_str());
		c = static_cast<char>(i);
		f = static_cast<float>(i);
		d = static_cast<double>(i);
		break;
	case FLOAT:
		f = std::atof(l_str.c_str());
		i = static_cast<int>(f);
		c = static_cast<char>(f);
		d = static_cast<double>(f);
		break;
	case DOUBLE:
		d = strtod(l_str.c_str(), NULL);
		i = static_cast<int>(d);
		c = static_cast<char>(d);
		f = static_cast<float>(d);
		break;
	case CHAR:
		c = l_str.at(0);
		i = static_cast<int>(c);
		f = static_cast<float>(c);
		d = static_cast<double>(c);
		break;
	}
	std::cout << YELLOW << "Convert" << RESET << " | " << YELLOW << "litteral string " << RESET << "\"" << BLUE << l_str << RESET << "\"" << std::endl;
	PrintConvert(i, f, d, c);
}

void ScalarConverter::PrintConvert(int i, float f, double d, char c)
{
	{
		if (i >= 0 && i <= 127)
		{
			if (std::isprint(c))
				std::cout << "        |  -" << MAGENTA << " char   " << RESET << ": '" << BLUE << c << RESET << "'" << std::endl;
			else
				std::cout << "        |  -" << MAGENTA << " char   " << RESET << ": " << BLUE << "Non displayable" << RESET << std::endl;
		}
		else
			std::cout << "        |  -" << MAGENTA << " char   " << RESET << ": " << BLUE << "impossible" << RESET << std::endl;
	}
	{
		if (d != d || static_cast<double>(i) >= std::numeric_limits<int>::max() || static_cast<double>(i) <= std::numeric_limits<int>::min())
			std::cout << "        |  -" << MAGENTA << " int    " << RESET << ": " << BLUE << "impossible" << RESET << std::endl;
		else
			std::cout << "        |  -" << MAGENTA << " int    " << RESET << ": " << BLUE << i << RESET << std::endl;
	}
	{
		if (static_cast<double>(f) >= std::numeric_limits<float>::max() || static_cast<double>(f) <= std::numeric_limits<float>::min()) {
			if (f >= std::numeric_limits<float>::max()) {
				std::cout << "        |  -" << MAGENTA << " float  " << RESET << ": " << BLUE << "inff" << RESET << std::endl;
			}
			else if (f >= std::numeric_limits<float>::min()) {
				std::cout << "        |  -" << MAGENTA << " float  " << RESET << ": " << BLUE << "-inff" << RESET << std::endl;
			}
		}
		int checkDecimal = static_cast<int>(f);
		if (f <= 999999.0f && f >= -999999.0f) {
			if (static_cast<float>(checkDecimal) == f)
				std::cout << "        |  -" << MAGENTA << " float  " << RESET << ": " << BLUE << f << ".0f" << RESET << std::endl;
			else
				std::cout << "        |  -" << MAGENTA << " float  " << RESET << ": " << BLUE << f << "f" << RESET << std::endl;
		}
		else
			std::cout << "        |  -" << MAGENTA << " float  " << RESET << ": " << BLUE << f << "f" << RESET << std::endl;
	}
	{
		int checkDecimal = static_cast<int>(d);
		if (static_cast<double>(checkDecimal) == d && d <= 999999 && d >= -999999)
			std::cout << "        |  -" << MAGENTA << " Double " << RESET << ": " << BLUE << d << ".0" << RESET << std::endl;
		else
			std::cout << "        |  -" << MAGENTA << " Double " << RESET << ": " << BLUE << d << RESET << std::endl;
	}
}

// void ScalarConverter::ConvertToInt(double const litteralDouble)
// {
// 	if (litteralDouble != litteralDouble || litteralDouble >= std::numeric_limits<int>::max() || litteralDouble <= std::numeric_limits<int>::min())
// 	{
// 		std::cout << "        |  -" << MAGENTA << " int    " << RESET << ": " << BLUE << "impossible" << RESET << std::endl;
// 		return;
// 	}
// 	std::cout << "        |  -" << MAGENTA << " int    " << RESET << ": " << BLUE << static_cast<int>(litteralDouble) << RESET << std::endl;
// }
// void ScalarConverter::ConvertToFloat(double const litteralDouble)
// {
// 	if (litteralDouble >= std::numeric_limits<float>::max() || litteralDouble <= std::numeric_limits<float>::min()) {
// 		if (litteralDouble >= std::numeric_limits<float>::max()) {
// 			std::cout << "        |  -" << MAGENTA << " float  " << RESET << ": " << BLUE << "inff" << RESET << std::endl;
// 			return;
// 		}
// 		else if (litteralDouble >= std::numeric_limits<float>::min()) {
// 			std::cout << "        |  -" << MAGENTA << " float  " << RESET << ": " << BLUE << "-inff" << RESET << std::endl;
// 			return;
// 		}
// 	}
// 	int checkDecimal = static_cast<int>(litteralDouble);
// 	if (litteralDouble <= 999999 && litteralDouble >= -999999) {
// 		if (static_cast<double>(checkDecimal) == litteralDouble)
// 			std::cout << "        |  -" << MAGENTA << " float  " << RESET << ": " << BLUE << static_cast<float>(litteralDouble) << ".0f" << RESET << std::endl;
// 		else
// 			std::cout << "        |  -" << MAGENTA << " float  " << RESET << ": " << BLUE << static_cast<float>(litteralDouble) << "f" << RESET << std::endl;
// 	}
// 	else
// 		std::cout << "        |  -" << MAGENTA << " float  " << RESET << ": " << BLUE << static_cast<float>(litteralDouble) << "f" << RESET << std::endl;
	
// }
// void ScalarConverter::ConvertToChar(double const litteralDouble)
// {
// 	if (static_cast<int>(litteralDouble) >= 0 && static_cast<int>(litteralDouble) <= 128)
// 	{
// 		if (std::isprint(static_cast<char>(litteralDouble)))
// 			std::cout << "        |  -" << MAGENTA << " char   " << RESET << ": '" << BLUE << static_cast<char>(litteralDouble) << RESET << "'" << std::endl;
// 		else
// 			std::cout << "        |  -" << MAGENTA << " char   " << RESET << ": " << BLUE << "Non displayable" << RESET << std::endl;
// 	}
// 	else
// 		std::cout << "        |  -" << MAGENTA << " char   " << RESET << ": " << BLUE << "impossible" << RESET << std::endl;
// }

// void ScalarConverter::ConvertToDouble(double const litteralDouble)
// {
// 	int checkDecimal = static_cast<int>(litteralDouble);
// 	if (static_cast<double>(checkDecimal) == litteralDouble && litteralDouble <= 999999 && litteralDouble >= -999999)
// 		std::cout << "        |  -" << MAGENTA << " Double " << RESET << ": " << BLUE << static_cast<double>(litteralDouble) << ".0" << RESET << std::endl;
// 	else
// 		std::cout << "        |  -" << MAGENTA << " Double " << RESET << ": " << BLUE << static_cast<double>(litteralDouble) << RESET << std::endl;
// }

/*
** --------------------------------- EXCEPTION ----------------------------------
*/

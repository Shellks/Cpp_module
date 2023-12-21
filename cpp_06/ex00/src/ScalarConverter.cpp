/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:01:26 by acarlott          #+#    #+#             */
/*   Updated: 2023/12/21 14:40:00 by acarlott         ###   ########lyon.fr   */
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
	ConvertType(l_str, type, &i, &f, &d, &c);
	std::cout << YELLOW << "Convert" << RESET << " | " << YELLOW << "litteral string " << RESET << "\"" << BLUE << l_str << RESET << "\"" << std::endl;
	PrintChar(c, i);
	PrintInt(i, d);
	PrintFloat(f, d);
	PrintDouble(d);
}

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
				f_count++;;
		}
		std::cout << point_count << std::endl;
		if (point_count == 1 && !l_str->c_str()[l_str->find(".") - 1])
			return (false);
		if (l_str->size() != (l_str->find("f") + 1) || point_count != 1 || f_count != 1 || l_str->find_first_of("0123456789") == std::string::npos)
			return (false);
		*type = FLOAT;
		return (true);
	}
	if (l_str->find(".") != std::string::npos && l_str->find("f") == std::string::npos)
	{
		size_t pos = l_str->find(".");
		int point_count = 0;
		for (size_t i = 0; i < l_str->length(); i++) {
			if (l_str->at(i) == '.')
				point_count++;
		}
		if (point_count != 1 || !l_str->c_str()[pos - 1])
			return (false);
		*type = DOUBLE;
	}
	else
		*type = INT;
	return (true);
}



void ScalarConverter::ConvertType(std::string l_str, unsigned int type, int *i, float *f, double *d, char *c)
{
	switch (type)
	{
		case INT:
			if (strtod(l_str.c_str(), NULL) >= std::numeric_limits<int>::max() || strtod(l_str.c_str(), NULL) <= std::numeric_limits<int>::min())
			{
				*d = strtod(l_str.c_str(), NULL);
				*i = static_cast<int>(*d);
			}
			else
			{
				*i = std::atoi(l_str.c_str());
				*d = static_cast<double>(*i);
			}
			std::cout << "is int" << std::endl;
			*c = static_cast<char>(*i);
			*f = static_cast<float>(*i);
			break;
		case FLOAT:
			if (strtod(l_str.c_str(), NULL) >= std::numeric_limits<double>::max() || strtod(l_str.c_str(), NULL) <= std::numeric_limits<double>::min())
			{
				*d = strtod(l_str.c_str(), NULL);
				*f = static_cast<float>(*d);
			}
			else
			{
				*f = std::atof(l_str.c_str());
				*d = static_cast<double>(*f);
			}
			*i = static_cast<int>(*f);
			*c = static_cast<char>(*f);
			break;
		case DOUBLE:
			*d = strtod(l_str.c_str(), NULL);
			*i = static_cast<int>(*d);
			*c = static_cast<char>(*d);
			*f = static_cast<float>(*d);
			break;
		case CHAR:
			*c = l_str.at(0);
			*i = static_cast<int>(*c);
			*f = static_cast<float>(*c);
			*d = static_cast<double>(*c);
			break;
	}
}

void ScalarConverter::PrintChar(char c, int i)
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
void ScalarConverter::PrintInt(int i, double d)
{
	if (d != d || d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
			std::cout << "        |  -" << MAGENTA << " int    " << RESET << ": " << BLUE << "impossible" << RESET << std::endl;
		else
			std::cout << "        |  -" << MAGENTA << " int    " << RESET << ": " << BLUE << i << RESET << std::endl;
}
void ScalarConverter::PrintFloat(float f, double d)
{
	bool isprint = false;
		if (d > std::numeric_limits<float>::max() || std::fabs(d) > std::numeric_limits<float>::max()) {
			if (d > std::numeric_limits<float>::max()) {
				std::cout << "        |  -" << MAGENTA << " float  " << RESET << ": " << BLUE << "inff" << RESET << std::endl;
			}
			else {
				std::cout << "        |  -" << MAGENTA << " float  " << RESET << ": " << BLUE << "-inff" << RESET << std::endl;
			}
			isprint = true;
		}
		if (isprint != true) {
			int checkDecimal = static_cast<int>(f);
			if (f <= 999999.0f && f >= -999999.0f) {
				if (static_cast<double>(checkDecimal) == f)
					std::cout << "        |  -" << MAGENTA << " float  " << RESET << ": " << BLUE << f << ".0f" << RESET << std::endl;
				else
					std::cout << "        |  -" << MAGENTA << " float  " << RESET << ": " << BLUE << f << "f" << RESET << std::endl;
			}
			else
				std::cout << "        |  -" << MAGENTA << " float  " << RESET << ": " << BLUE << f << "f" << RESET << std::endl;
		}
}
void ScalarConverter::PrintDouble(double d)
{
	int checkDecimal = static_cast<int>(d);
	if (static_cast<double>(checkDecimal) == d && d <= 999999 && d >= -999999)
		std::cout << "        |  -" << MAGENTA << " Double " << RESET << ": " << BLUE << d << ".0" << RESET << std::endl;
	else
		std::cout << "        |  -" << MAGENTA << " Double " << RESET << ": " << BLUE << d << RESET << std::endl;
}

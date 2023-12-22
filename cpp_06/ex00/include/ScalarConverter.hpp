/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:00:12 by acarlott          #+#    #+#             */
/*   Updated: 2023/12/21 14:20:01 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#define RESET "\033[0m"
#define BROWN "\033[0;33m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

#define INT 1
#define CHAR 2
#define FLOAT 3
#define DOUBLE 4

#include <iostream>
#include <cstdlib>
#include <limits>
#include <string>
#include <cmath>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(ScalarConverter const &src);
	~ScalarConverter();

	ScalarConverter &operator=(ScalarConverter const &src);
	static void ConvertType(std::string l_str, unsigned int type, int *i, float *f, double *d, char *c);
	static bool ConvertParser(std::string *l_str, unsigned int *type);
	static void PrintInt(int i, double d);
	static void PrintFloat(float f, double d);
	static void PrintChar(char c, int i);
	static void PrintDouble(double d);

public:
	static void convert(std::string litteralString);
};

#endif

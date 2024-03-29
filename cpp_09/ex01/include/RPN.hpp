/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 09:07:28 by acarlott          #+#    #+#             */
/*   Updated: 2024/02/09 12:25:46 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#define RESET "\033[0m"
#define RED "\033[31m"
#define PREFIX_ERROR "Error: RPN: "

#include <iostream>
#include <stack> //std::stack
#include <sstream> //std::istringstream
#include <cstdlib> //strtod

int	RPNCalculator(std::string const calcul);

class InvalidOperandException : public std::exception {
	public:
		virtual const char *what(void) const throw();
};

class InvalidOperatorException : public std::exception {
	public:
		virtual const char *what(void) const throw();
};

class ParenthesisException : public std::exception {
	public:
		virtual const char *what(void) const throw();
};

class ZeroDividedException : public std::exception {
	public:
		virtual const char *what(void) const throw();
};

class WrongCalculException : public std::exception {
	public:
		virtual const char *what(void) const throw();
};

#endif

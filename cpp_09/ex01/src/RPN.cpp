/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 09:08:23 by acarlott          #+#    #+#             */
/*   Updated: 2024/02/09 09:15:11 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"

static void operatorManager(std::stack<int> *RPNStack, std::string const token, int *nbOperator)
{
	int	firstOperand = 0;
	int	secondOperand = 0;
	
	if (!RPNStack->empty()) {
		secondOperand = RPNStack->top();
		RPNStack->pop();
	}
	if (!RPNStack->empty()) {
		firstOperand = RPNStack->top();
		RPNStack->pop();
	}
	else
		throw(WrongCalculException());
	if (token[0] == '+')
		RPNStack->push(firstOperand + secondOperand);
	else if (token[0] == '-')
		RPNStack->push(firstOperand - secondOperand);
	else if (token[0] == '*')
		RPNStack->push(firstOperand * secondOperand);
	else if (token[0] == '/') {
		if (firstOperand == 0 || secondOperand == 0)
			throw(ZeroDividedException());
		RPNStack->push(firstOperand / secondOperand);
	}
	nbOperator++;
}

static void isValidCalcul(std::string token)
{
	for (size_t i = 0; i < token.size(); i++) {
		if (token[i] == '(' && token.find(')') != std::string::npos)
			throw(ParenthesisException());
		else if (token.size() > 1 && token[i] == '-') {
			if (token[i + 1] && std::isdigit(token[i + 1])) {
				for (size_t j = i + 1; j < token.size(); j++)
					if (!std::isdigit(token[j]))
						throw(InvalidOperandException());
			}
			else
				throw(InvalidOperandException());
		}
		else if (token.size() > 1 && !std::isdigit(token[i]))
			throw(InvalidOperandException());
		else if (token.size() == 1 && !std::isdigit(token[i]) && token.find_first_of("-+/*") == std::string::npos)
			throw(InvalidOperatorException());
	}
}

int	RPNCalculator(std::string const calcul)
{
	std::stack<int>		RPNStack;
	std::istringstream	iss(calcul);
	std::string			token;
	double				size_check;
	int					nbOperand = 0;
	int					nbOperator = 0;
	
	while (iss >> token) {
		isValidCalcul(token);
		if (token.size() == 1 && !std::isdigit(token[0]))
			operatorManager(&RPNStack, token, &nbOperator);
		else {
			size_check = strtod(token.c_str(), NULL);
			if (size_check > 9 || size_check < -9)
				throw(InvalidOperandException());
			RPNStack.push(static_cast<int>(size_check));
			nbOperand++;
		}
	}
	if (nbOperator >= nbOperand || RPNStack.size() != 1)
		throw(WrongCalculException());
	return (RPNStack.top());
}

/*
** --------------------------------- EXCEPTION ----------------------------------
*/

const char *InvalidOperandException::what(void) const throw() {
	return ("Invalid operand");
}

const char *InvalidOperatorException::what(void) const throw() {
	return ("Invalid operator");
}

const char *ParenthesisException::what(void) const throw() {
	return ("Unsupported parenthesis");
}

const char *ZeroDividedException::what(void) const throw() {
	return ("Division by 0 impossible");
}

const char *WrongCalculException::what(void) const throw() {
	return ("impossible calculation");
}

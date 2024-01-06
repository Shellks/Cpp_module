/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 09:08:23 by acarlott          #+#    #+#             */
/*   Updated: 2024/01/06 15:12:32 by acarlott         ###   ########lyon.fr   */
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
	// int finalOperand = RPNStack->top();
	// std::cout << "first: " << firstOperand << " second: " << secondOperand << " operand: " << token[0] << " result: " << finalOperand << std::endl;
}

int	RPNCalculator(std::string const calcul)
{
	std::stack<int>		RPNStack;
	std::istringstream	iss(calcul);
	std::string			token;
	int					nbOperand = 0;
	int					nbOperator = 0;
	
	while (iss >> token) {
		for (size_t i = 0; i < token.size(); i++) {
			if (token[i] == '(' && token.find(')') != std::string::npos)
				throw(ParenthesisException());
			else if (token.size() > 1 && !std::isdigit(token[i]))
				throw(NotDigitException());
			else if (token.size() == 1 && !std::isdigit(token[i]) && token.find_first_of("-+/*") == std::string::npos)
				throw(InvalidOperandException());
		}
		if (std::isdigit(token[0])) {
			RPNStack.push(std::atoi(token.c_str()));
			nbOperand++;
		}
		else
			operatorManager(&RPNStack, token, &nbOperator);
	}
	if (nbOperator >= nbOperand || RPNStack.size() != 1)
		throw(WrongCalculException());
	return (RPNStack.top());
}

/*
** --------------------------------- EXCEPTION ----------------------------------
*/

const char *NotDigitException::what(void) const throw() {
	return ("Invalid operand");
}

const char *InvalidOperandException::what(void) const throw() {
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

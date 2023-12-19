/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:19:30 by acarlott          #+#    #+#             */
/*   Updated: 2023/12/19 14:01:14 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.hpp"

Span::Span()
{
}

Span::Span(unsigned int sizeMax) : _sizeMax(sizeMax)
{
	std::cout << "-" << GREEN << "Container created" << RESET << " ! he have a size of " << CYAN << this->_sizeMax << RESET << std::endl;
}

Span::Span(Span const &src)
{
	if (this != &src)
		this->_sizeMax = src._sizeMax;
}

Span::~Span()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Span &Span::operator=(Span const &src)
{
	if (this != &src)
		this->_sizeMax = src._sizeMax;
	return *this;
}
/*
** --------------------------------- METHODS ----------------------------------
*/

void Span::addNumber(unsigned int number)
{
	if (this->_sizeMax <= this->_tab.size())
		throw(Span::MaxSizeException());
	this->_tab.push_back(number);
}

void Span::addNumber(int *newTab, unsigned int size)
{
	if (this->_sizeMax <= this->_tab.size() + size)
		throw(Span::MaxSizeException());
	this->_tab.insert(this->_tab.end(), newTab, (newTab + size));
	for (unsigned int i = 0; i <= size; i++)
		std::cout << " -" << GREEN << "Adding" << RESET << " '" << CYAN << newTab[i] << RESET << "' to " << YELLOW << "container" << RESET << std::endl;
}

unsigned int Span::shortestSpan(void)
{
	std::vector<int>	sorted_tab = this->_tab;
	int					smallestSpan = std::numeric_limits<int>::max();
	
	if (this->_tab.size() < 2)
		throw(Span::NotEnoughNumberException());

	std::sort(sorted_tab.begin(), sorted_tab.end());
	for (std::vector<int>::iterator it = (sorted_tab.begin() + 1); it < sorted_tab.end(); it++)
		if ((*it - *(it - 1)) < smallestSpan)
			smallestSpan = (*it - *(it - 1));
	return (static_cast<unsigned int>(smallestSpan));
}
unsigned int Span::longestSpan(void)
{
	std::vector<int>	sorted_tab = this->_tab;
	
	if (this->_tab.size() < 2)
		throw(Span::NotEnoughNumberException());

	std::sort(sorted_tab.begin(), sorted_tab.end());
	return (static_cast<unsigned int>(sorted_tab[sorted_tab.size() - 1] - sorted_tab[0]));
}
/*
** --------------------------------- EXCEPTION ----------------------------------
*/

const char *Span::MaxSizeException::what() const throw()
{
	return ("Container is already full");
};

const char *Span::NotEnoughNumberException::what() const throw()
{
	return ("Not enough numbers in container for comparison");
};
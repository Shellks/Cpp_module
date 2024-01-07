/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 09:08:23 by acarlott          #+#    #+#             */
/*   Updated: 2024/01/07 11:20:51 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

/*
** --------------------------------- CONSTRUCTOR/DESTRUCTOR ---------------------------------
*/

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(char **args)
{
	this->PmergeMeParser(args);
}

PmergeMe::PmergeMe(PmergeMe const &src)
{
	(void)src;
}

PmergeMe::~PmergeMe()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PmergeMe &PmergeMe::operator=(PmergeMe const &src)
{
	(void)src;
	return *this;
}

/*
** --------------------------------- METHODS ---------------------------------
*/

void	PmergeMe::PmergeMeParser(char **args)
{
	for (char **tab = args; *tab; tab++) {
		for (char *str = *tab; *str; str++) {
			std::cout << *str << std::endl;
			if (!std::isdigit(*str))
				throw(PmergeMe::WrongSequenceException(str));
		}
	}
}

/*
** --------------------------------- EXCEPTION ---------------------------------
*/

const char *PmergeMe::WrongSequenceException::what(char const &str) const throw()
{
	return ("Invalid integers sequence: " + str);
}

const char *PmergeMe::EmptyFileException::what(void) const throw()
{
	return ("Empty file");
}

const char *PmergeMe::BadFileException::what(void) const throw()
{
	return ("Bad file format: \"date | amount\"\n-date: \"Year-Month-Day\"\n-amount: \"int/float\"");
}
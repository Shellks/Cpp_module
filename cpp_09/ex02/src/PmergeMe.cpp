/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 09:08:23 by acarlott          #+#    #+#             */
/*   Updated: 2024/01/15 19:48:20 by acarlott         ###   ########lyon.fr   */
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
	this->_PmergeMeParser(args);
	std::cout << "vector: before: " << std::endl;
	for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); ++it) {
	std::cout << "- " << *it << std::endl;
	};
	this->_SortVector(this->_vector);
	std::cout << "vector: after: " << std::endl;
	for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); ++it) {
	std::cout << "- " << *it << std::endl;
	};
	std::cout << "list: before: " << std::endl;
	for (std::list<int>::iterator it = _list.begin(); it != _list.end(); ++it) {
		std::cout << "- " << *it << std::endl;
	};
	this->_SortList(this->_list);
	std::cout << "list: after: " << std::endl;
	for (std::list<int>::iterator it = _list.begin(); it != _list.end(); ++it) {
		std::cout << "- " << *it << std::endl;
	};
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


void	PmergeMe::_PmergeMeParser(char **args)
{
	int		sign_count;
	double	size_check;
	for (char **tab = args; *tab; tab++) {
		sign_count = 0;
		if (!*tab[0])
			throw(PmergeMe::WrongSequenceException());
		for (char *str = *tab; *str; str++) {
			if (!std::isdigit(*str)) {
				if (*str == '+' && ++str && std::isdigit(*str) && sign_count == 0) {
					sign_count++;
					continue ;
				}
				else
					throw(PmergeMe::WrongSequenceException());
			}
		}
		size_check = strtod(*tab, NULL);
		if (size_check < 0 || size_check > std::numeric_limits<int>::max())
			throw(PmergeMe::OverflowSequenceException());
		this->_list.push_back(static_cast<int>(size_check));
		this->_vector.push_back(static_cast<int>(size_check));
	}
}

void	PmergeMe::_SortList(list &toSort)
{
	if (toSort.size() <= 1)
		return ;
	size_t	half = (toSort.size() / 2);
	itList	it = toSort.begin();
	list	lowPart;
	list	result;

	for (size_t i = 0; i < half; i++) {
			lowPart.push_back(*it);
			it++;
	}
	list	highPart(it, toSort.end());
	_SortList(lowPart);
	_SortList(highPart);
	itList	lowPartIt = lowPart.begin();
	itList	highPartIt = highPart.begin();
	while (lowPartIt != lowPart.end() && highPartIt != highPart.end()) {
		if (*lowPartIt < *highPartIt) {
			result.push_back(*lowPartIt);
			lowPartIt++;
		}
		else {
			result.push_back(*highPartIt);
			highPartIt++;
		}
	}
	result.insert(result.end(), lowPartIt, lowPart.end());
	result.insert(result.end(), highPartIt, highPart.end());
	toSort = result;
}

void	PmergeMe::_SortVector(vector &toSort)
{
	if (toSort.size() <= 1)
		return ;
	size_t	half = (toSort.size() / 2);
	vector	lowPart(toSort.begin(), toSort.begin() + half);
	vector	highPart(toSort.begin() + half, toSort.end());
	vector	result;

	_SortVector(lowPart);
	_SortVector(highPart);
	itVector	lowPartIt = lowPart.begin();
	itVector	highPartIt = highPart.begin();
	while (lowPartIt != lowPart.end() && highPartIt != highPart.end()) {
		if (*lowPartIt < *highPartIt) {
			result.push_back(*lowPartIt);
			lowPartIt++;
		}
		else {
			result.push_back(*highPartIt);
			highPartIt++;
		}
	}
	result.insert(result.end(), lowPartIt, lowPart.end());
	result.insert(result.end(), highPartIt, highPart.end());
	toSort = result;
}

/*
** --------------------------------- EXCEPTION ---------------------------------
*/

const char *PmergeMe::WrongSequenceException::what(void) const throw()
{
	return ("Invalid input, only positive integers allowed");
}

const char *PmergeMe::OverflowSequenceException::what(void) const throw()
{
	return ("Invalid int overflow in sequence ");
}

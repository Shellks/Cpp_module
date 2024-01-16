/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 09:08:23 by acarlott          #+#    #+#             */
/*   Updated: 2024/01/16 18:13:39 by acarlott         ###   ########lyon.fr   */
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
	this->_PmergeMeSort(args);
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

void	PmergeMe::_PmergeMeSort(char **args)
{
	std::cout << "Before: " << std::flush;
	for (char **tab = args; *tab; tab++) {
		this->_vector.push_back((std::atoi(*tab)));
		std::cout << this->_vector.back() << " " << std::flush;
	}
	this->_vector.clear();
	std::cout << std::endl;
	clock_t startTime = clock();
	for (char **tab = args; *tab; tab++)
		this->_vector.push_back((std::atoi(*tab)));
	this->_SortVector(this->_vector);
	clock_t endTime = clock();
	std::cout << "After: " << std::flush;
	for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); it++)
		std::cout << *it << " " << std::flush;
	std::cout << std::endl;
	double	execTime = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << this->_vector.size() << " elements with std::vector : "  << std::fixed << std::setprecision(6) << execTime << " us" << std::endl;
	startTime = clock();
	for (char **tab = args; *tab; tab++)
		this->_list.push_back((std::atoi(*tab)));
	this->_SortList(this->_list);
	endTime = clock();
	execTime = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << this->_list.size() << " elements with std::list : " << std::fixed << std::setprecision(6) << execTime << " us" << std::endl;
}

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 09:08:23 by acarlott          #+#    #+#             */
/*   Updated: 2024/02/02 16:11:05 by acarlott         ###   ########lyon.fr   */
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
	if (toSort.size() <= 2)
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
	// std::cout << "low part: " << std::endl;
	// for (itList it = lowPart.begin(); it != lowPart.end(); it++) {
	// 	std::cout << *it << " " << std::endl;
	// }
	// std::cout << "high part: " << std::endl;
	// for (itList it = highPart.begin(); it != highPart.end(); it++) {
	// 	std::cout << *it << " " << std::endl;
	// }
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
	std::vector<std::pair<int, int> >	pairs;
	int									temp;
	
	for (size_t i = 0; i < toSort.size(); i += 2) {
		if (i + 1 < toSort.size())
			pairs.push_back(std::make_pair(toSort[i], toSort[i + 1]));
		else
			pairs.push_back(std::make_pair(toSort[i], ODD));
		if (pairs.back().second != ODD && pairs.back().first < pairs.back().second) {
				temp = pairs.back().first;
				pairs.back().first = pairs.back().second;
				pairs.back().second = temp;
		}
	}
	pairs = this->_recursiveMerge(pairs);
	for (size_t i = 0; i < pairs.size(); i++) {
		std::cout << pairs[i].first << " " << pairs[i].second << " " << std::endl;
	}
	toSort.clear();
	toSort.push_back(pairs.front().second);
	for (size_t i = 0; i < pairs.size(); i++) {
		if (pairs[i].first != ODD && pairs[i].second != ODD)
			toSort.push_back(pairs[i].first);
		else if (pairs[i].second == ODD) {
			pairs.push_back(std::make_pair(ODD, pairs[i].first));
			pairs.erase(pairs.begin() + i);
		}
	}
	size_t index = 0;
	size_t area = 1;
	for (size_t i = 1; index < pairs.size() - 1; i++) {
		index += area;
		area = (area << 1) - 1;
		itVector it = std::lower_bound(toSort.begin(), toSort.end(), pairs[index].second);
		toSort.insert(it, pairs[index].second);
	}
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

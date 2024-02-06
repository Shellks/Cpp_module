/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 09:08:23 by acarlott          #+#    #+#             */
/*   Updated: 2024/02/06 15:44:28 by acarlott         ###   ########lyon.fr   */
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
	clock_t startTime = clock();
	for (char **tab = args; *tab; tab++)
		this->_vector.push_back((std::atoi(*tab)));
	this->_SortVector(this->_vector);
	clock_t endTime = clock();
	std::cout << std::endl << "After: " << std::flush;
	for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); it++)
		std::cout << *it << " " << std::flush;
	std::cout << std::endl << "Time to process a range of " << this->_vector.size() << " elements with std::vector : " << std::flush;
	std::cout << std::fixed << std::setprecision(6) << (static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC) << " us" << std::endl;
	startTime = clock();
	for (char **tab = args; *tab; tab++)
		this->_list.push_back((std::atoi(*tab)));
	this->_SortList(this->_list);
	endTime = clock();
	std::cout << "Time to process a range of " << this->_list.size() << " elements with std::list : " << std::flush;
	std::cout << std::fixed << std::setprecision(6) << (static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC) << " us" << std::endl;
	std::cout << std::endl << "After: " << std::flush;
	for (std::list<int>::iterator it = _list.begin(); it != _list.end(); it++)
		std::cout << *it << " " << std::flush;
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
	std::list<std::pair<int, int> >	pairs;
	
	for (itList it = toSort.begin(); it != toSort.end(); it++) {
		int first = *it;
		if (++it != toSort.end())
			pairs.push_back(std::make_pair(first, *it));
		else {
			pairs.push_back(std::make_pair(first, ODD));
			break ;
		}
		if (pairs.back().second != ODD && pairs.back().first < pairs.back().second) {
				int temp = pairs.back().first;
				pairs.back().first = pairs.back().second;
				pairs.back().second = temp;
		}
	}
	pairs = this->_recursiveMerge(pairs);
	toSort.clear();
	for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++) {
		if (it->second == ODD) {
			pairs.push_back(std::make_pair(ODD, it->first));
			it = pairs.erase(it);
		}
	}
	toSort.push_back(pairs.front().second);
	for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++) {
		if (it->first != ODD && it->second != ODD)
			toSort.push_back(it->first);
	}
	size_t index = 0;
	size_t area = 0;
	for (size_t i = 0; index < pairs.size() - 1; i++) {
		area = (1 << (i + 1)) - area;
		index += area;
		if (index >= pairs.size()) {
			area += pairs.size() - 1 - index;
			index = pairs.size() - 1;
		}
		std::list<std::pair<int, int> >::iterator it = pairs.begin();
		std::advance(it, index);
		for (size_t j = 0; j < area; j++) {
			toSort.insert(std::lower_bound(toSort.begin(), toSort.end(), it->second), it->second);
			it--;
		}
	}
}

void	PmergeMe::_SortVector(vector &toSort)
{
	std::vector<std::pair<int, int> >	pairs;
	
	for (size_t i = 0; i < toSort.size(); i += 2) {
		if (i + 1 < toSort.size())
			pairs.push_back(std::make_pair(toSort[i], toSort[i + 1]));
		else
			pairs.push_back(std::make_pair(toSort[i], ODD));
		if (pairs.back().second != ODD && pairs.back().first < pairs.back().second) {
				int temp = pairs.back().first;
				pairs.back().first = pairs.back().second;
				pairs.back().second = temp;
		}
	}
	pairs = this->_recursiveMerge(pairs);
	toSort.clear();
	for (size_t i = 0; i < pairs.size(); i++) {
		if (pairs[i].second == ODD) {
			pairs.push_back(std::make_pair(ODD, pairs[i].first));
			pairs.erase(pairs.begin() + i);
		}
	}
	toSort.push_back(pairs.front().second);
	for (size_t i = 0; i < pairs.size(); i++)
		if (pairs[i].first != ODD)
			toSort.push_back(pairs[i].first);
	size_t index = 0;
	size_t area = 0;
	for (size_t i = 0; index < pairs.size() - 1; i++) {
		area = (1 << (i + 1)) - area;
		index += area;
		if (index >= pairs.size()) {
			area += pairs.size() - 1 - index;
			index = pairs.size() - 1;
		}
		for (size_t j = 0; j < area; j++) {
			toSort.insert(std::lower_bound(toSort.begin(), toSort.end(), pairs[index - j].second), pairs[index - j].second);
		}
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

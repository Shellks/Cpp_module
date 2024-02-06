/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 09:07:28 by acarlott          #+#    #+#             */
/*   Updated: 2024/02/06 12:56:36 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define CYAN "\033[36m"
#define PREFIX_ERROR "Error: PmergeMe: "

#include <iostream>
#include <iomanip> // std::fixed - std::precision
#include <list> //std::list
#include <vector> //std::vector
#include <limits> //int min/max
#include <cstdlib> // strtod (convert str to double)
#include <cctype> //std::isdigit
#include <cstdlib> //std::atoi
#include <iterator> //std::next
#include <ctime> //clock

#define ODD -1

typedef std::vector<int> vector;
typedef vector::iterator itVector;
typedef std::list<int> list;
typedef list::iterator itList;

class PmergeMe
{
	private:
		vector	_vector;
		list	_list;
	
		PmergeMe();

		void	_PmergeMeParser(char **args);
		void	_PmergeMeSort(char **args);
		void	_SortVector(vector &_vector);
		void	_SortList(list &_list);
		
		template< typename T >
		T		_recursiveMerge(T &pairs) {
			T	first;
			T	second;
			T	mergedPairs;
			size_t count = 0;
			size_t	half = (pairs.size() / 2);
			
			for (typename T::iterator it = pairs.begin(); it != pairs.end(); it++) {
				if (count < half)
					first.push_back(*it);
				else
					second.push_back(*it);
				count++;
			}
			pairs.clear();
			if (first.size() > 1)
				this->_recursiveMerge(first);
			if (second.size() > 1)
				this->_recursiveMerge(second);
			typename T::iterator it_first = first.begin();
			typename T::iterator it_second = second.begin();
			while (it_first != first.end() || it_second != second.end()) {
				if (it_second == second.end() || (it_first != first.end() && it_first->first < it_second->first)) {
					pairs.push_back(*it_first);
					it_first++;
				}
				else {
					pairs.push_back(*it_second);
					it_second++;
				}
			}
			return (pairs);
		};
		
	public:
		PmergeMe(char **args);
		PmergeMe(PmergeMe const &src);
		~PmergeMe();

		PmergeMe &operator=(PmergeMe const &src);

		
		class WrongSequenceException : public std::exception {
			public:
				virtual const char *what(void) const throw();
		};
		class OverflowSequenceException : public std::exception {
			public:
				virtual const char *what(void) const throw();
		};
};

#endif

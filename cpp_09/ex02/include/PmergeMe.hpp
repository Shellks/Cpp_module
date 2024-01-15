/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 09:07:28 by acarlott          #+#    #+#             */
/*   Updated: 2024/01/15 19:28:47 by acarlott         ###   ########lyon.fr   */
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
#include <list> //std::list
#include <vector> //std::vector
#include <limits> //int min/max
#include <cstdlib> // strtod (convert str to double)
#include <cctype> //std::isdigit
#include <cstdlib> //std::atoi
#include <iterator> //std::next

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
		void	_SortVector(vector &_vector);
		void	_SortList(list &_list);
		
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

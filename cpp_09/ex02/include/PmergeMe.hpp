/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 09:07:28 by acarlott          #+#    #+#             */
/*   Updated: 2024/01/07 11:20:01 by acarlott         ###   ########lyon.fr   */
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
#include <list>
#include <vector>
#include <cctype> //std::isdigit
#include <cstdlib> //std::atoi

class PmergeMe
{
	private:
		std::vector<int>	_vector;
	
		PmergeMe();
		
	public:
		PmergeMe(char **args);
		PmergeMe(PmergeMe const &src);
		~PmergeMe();
		
		PmergeMe &operator=(PmergeMe const &src);

		void	PmergeMeParser(char **args);
	
		class WrongSequenceException : public std::exception {
			private:
				std::string errorMessage;

			public:
				WrongSequenceException(const std::string& message) : errorMessage(message) {};
				~WrongSequenceException() throw() {};
				virtual const char *what(char const &str) const throw();
		};
		class EmptyFileException : public std::exception {
			public:
				virtual const char *what(void) const throw();
		};
		class BadFileException : public std::exception {
			public:
				virtual const char *what(void) const throw();
		};
};

#endif

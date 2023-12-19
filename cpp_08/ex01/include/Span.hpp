/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:18:21 by acarlott          #+#    #+#             */
/*   Updated: 2023/12/19 14:05:51 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

#include <iostream>
#include <vector>
#include <limits>
#include <ctime>
#include <algorithm>

class Span
{
private:
	Span();

	unsigned int	_sizeMax;
	std::vector<int>	_tab;

public:
	Span(unsigned int sizeMax);
	Span(Span const &src);
	~Span();

	Span &operator=(Span const &src);

	void addNumber(unsigned int number);
	void addNumber(int * tab, unsigned int number);
	unsigned int shortestSpan(void);
	unsigned int longestSpan(void);
	
	class MaxSizeException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	class NotEnoughNumberException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};


#endif
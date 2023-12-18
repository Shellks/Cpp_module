/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:19:21 by acarlott          #+#    #+#             */
/*   Updated: 2023/12/18 21:57:19 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

#include <iostream>
#include <vector>
#include <algorithm>

class NoOccurenceException : public std::exception
{
	public:
		virtual const char *what() const throw() {
			return ("No occurence found");
		};
};

template< typename T>
void easyfind(T const &container, int to_find)
{
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
	{
		if (*it == to_find)
		{
			std::cout << " - " << GREEN << "Found! " << CYAN << to_find << YELLOW << " in the container." << RESET << std::endl;
			return;
		}
	}
	throw(NoOccurenceException());
}


#endif
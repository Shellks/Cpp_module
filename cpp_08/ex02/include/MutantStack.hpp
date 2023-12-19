/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:36:22 by acarlott          #+#    #+#             */
/*   Updated: 2023/12/19 17:03:29 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

#include <iostream>
# include <stack>
# include <iterator>
# include <vector>

template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() {}
		MutantStack(MutantStack const &src) {
			if (*this != src)
				*this = src;
		}
		~MutantStack() {}
	
		MutantStack &operator=(MutantStack const &src) {
			if (*this != src)
				*this = src;
		}
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator	begin(void) { return iterator(std::stack<T>::c.begin());}
		iterator	end(void) {return iterator(std::stack<T>::c.end());}
};


#endif
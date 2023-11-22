/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:22:45 by acarlott          #+#    #+#             */
/*   Updated: 2023/11/22 17:27:31 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Brain.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Brain::Brain() {
	std::cout << "Brain default constructor called!" << std::endl;
}

Brain::Brain(std::string name) {
	for (int i; i < 100; i++)
		ideas[i] = name;
	std::cout << "Brain string constructor called!" << std::endl;
}

Brain::Brain( const Brain & src ) {
	std::cout << "Brain copy constructor called!" << std::endl;
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Brain::~Brain() {
	std::cout << "Brain destructor called!" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Brain	&Brain::operator=( Brain const & src )
{
	if (this != &src)
		*this = src;
	return *this;
}

/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:22:45 by acarlott          #+#    #+#             */
/*   Updated: 2023/11/23 16:31:21 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Brain.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Brain::Brain() {
	std::cout << "Brain default constructor called!" << std::endl;
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
	if (this != &src) {
		for (int i = 0; i < 100; i++) {
			this->ideas[i] = src.ideas[i];
		}
	}
	return *this;
}

/* ************************************************************************** */

void		Brain::setIdeas( int index, std::string ideas ) {
	this->ideas[index] = ideas;
}

std::string	Brain::getIdeas( int index ) const {
	return (this->ideas[index]);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:36:18 by acarlott          #+#    #+#             */
/*   Updated: 2023/11/22 14:53:53 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongCat::WrongCat() : WrongAnimal("WrongCat"){
}

WrongCat::WrongCat( const WrongCat & src ) : WrongAnimal(src) {
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongCat::~WrongCat() {
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongCat &				WrongCat::operator=( WrongCat const & src ) {
	if ( this != &src ) {
		this->type = src.getType();
	}
	return *this;
}

/* ************************************************************************** */

void	WrongCat::makeSound(void) const {
	std::cout << "Meowwwouuu !" << std::endl;
}

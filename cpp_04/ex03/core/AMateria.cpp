/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:51:34 by acarlott          #+#    #+#             */
/*   Updated: 2023/11/24 13:38:51 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AMateria.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AMateria::AMateria() : type("None"){
}

AMateria::AMateria(std::string const & type) : type(type){
}

AMateria::AMateria( const AMateria & src ) {
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AMateria::~AMateria() {
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AMateria &	AMateria::operator=( AMateria const & src ) {
	if (this != &src) {
		this->type = src.type;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void AMateria::use(ICharacter& target) {
	
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/
	std::string const & AMateria::getType() const {
		return (this->type);
	}

/* ************************************************************************** */

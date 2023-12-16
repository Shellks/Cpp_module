/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:32:38 by acarlott          #+#    #+#             */
/*   Updated: 2023/12/16 10:43:19 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::Serializer(Serializer const &src)
{
	(void)src;
}

Serializer::~Serializer()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Serializer &Serializer::operator=(Serializer const &src)
{
	(void)src;
	return *this;
}
/*
** --------------------------------- METHODS ----------------------------------
*/

uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw) 
{
	return (reinterpret_cast<Data *>(raw));
}

/*
** --------------------------------- EXCEPTION ----------------------------------
*/
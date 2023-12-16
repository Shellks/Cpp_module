/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:32:34 by acarlott          #+#    #+#             */
/*   Updated: 2023/12/16 11:07:17 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Data.hpp"

Data::Data() : _value(42)
{
}

Data::Data(int value) : _value(value)
{
}

Data::Data(Data const &src) : _value(src._value)
{
}

Data::~Data()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Data &Data::operator=(Data const &src)
{
	this->_value = src._value;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

int Data::getValue(void) const
{
	return (this->_value);
}

/*
** --------------------------------- EXCEPTION ----------------------------------
*/
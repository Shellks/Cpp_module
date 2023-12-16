/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:27:45 by acarlott          #+#    #+#             */
/*   Updated: 2023/12/16 11:20:55 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Serializer.hpp"

int main(void)
{
	{
		Data	*dataPtr = new Data();
		uintptr_t	serialize = Serializer::serialize(dataPtr);
		Data	*deserialize = Serializer::deserialize(serialize);
		
		std::cout << YELLOW << "Meta test: " << MAGENTA << "REINTERPRET_CAST" << RESET << std::endl;
		std::cout << MAGENTA << "DataPtr" << RESET << " <-> " << YELLOW << "adress" << RESET << ": " << BLUE << dataPtr << RESET << std::endl;
		std::cout << MAGENTA << "DataPtr" << RESET << " <-> " << YELLOW << "value" << RESET << ": " << BLUE << dataPtr->getValue() << RESET << std::endl;
		std::cout << MAGENTA << "DataPtr" << RESET << " <-> " << YELLOW << "serialized" << RESET << ": " << BLUE << serialize << RESET << std::endl;
		std::cout << MAGENTA << "DataPtr" << RESET << " <-> " << YELLOW << "deserialized adress" << RESET << ": " << BLUE << deserialize << RESET << std::endl;
		std::cout << MAGENTA << "DataPtr" << RESET << " <-> " << YELLOW << "deserialized value" << RESET << ": " << BLUE << deserialize->getValue() << RESET << std::endl;
		delete (dataPtr);
	}
}
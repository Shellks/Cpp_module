/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 11:25:36 by acarlott          #+#    #+#             */
/*   Updated: 2023/12/21 15:17:08 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Base.hpp"
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"

Base::~Base()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Base * generate(void) 
{
	std::srand(std::time(NULL));
	int rngValue = std::rand() % 3;
	switch (rngValue) {
	case 0:
		return (new A());
	case 1:
		return (new B());
	case 2:
		return (new C());
	default :
		return (NULL);
	}
}

void identify(Base* p) 
{
	std::cout << YELLOW << "Identify by pointer" << RESET << ":" << std::endl;
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "	- " << CYAN << "Generated class" << RESET << " : " << YELLOW << "A" << RESET << std::endl;
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "	- " << CYAN << "Generated class" << RESET << " : " << YELLOW << "B" << RESET << std::endl;
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << "	- " << CYAN << "Generated class" << RESET << " : " << YELLOW << "C" << RESET << std::endl;
}

void identify(Base& p) 
{
	Base	test;
	bool	isCatch = false;
	std::cout << YELLOW << "Identify by reference" << RESET << ":" << std::endl;
	try
	{
		test = dynamic_cast<A &>(p);
		std::cout << "	- " << CYAN << "Generated class" << RESET << " : " << YELLOW << "A" << RESET << std::endl;
		return;
	}
	catch (...) {
		isCatch = true;
	}
	try
	{
		test = dynamic_cast<B &>(p);
		std::cout << "	- " << CYAN << "Generated class" << RESET << " : " << YELLOW << "B" << RESET << std::endl;
		return;
	}
	catch (...) {
		isCatch = true;
	}
	try
	{
		test = dynamic_cast<C &>(p);
		std::cout << "	- " << CYAN << "Generated class" << RESET << " : " << YELLOW << "C" << RESET << std::endl;
		return;
	}
	catch (...) {
		isCatch = true;
	}
	if (isCatch == true)
		std::cerr << RED << "Error with dynamic cast !" << std::endl;
}

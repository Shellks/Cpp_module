/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:23:52 by acarlott          #+#    #+#             */
/*   Updated: 2023/09/29 15:49:10 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Harl.hpp"

Harl::Harl(void)
{
	return ;
}

Harl::~Harl(void)
{
	return ;
}

void Harl::complain( std::string level )
{
	void (Harl::*functiontab[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	complain[4] = {"debug", "info", "warning", "error"};

	for (int i = 0; i < 4; i++) {
		if (complain[i] == level)
			(this->*functiontab[i])();
	}
}

void Harl::debug( void )
{
	std::cout << "I love having extra bacon for my" \
	<< " 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!";
	std::cout << std::endl;
}

void Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money."\
	<< " You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!";
	std::cout << std::endl;
}

void Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free." \
	<< " I’ve been coming for years whereas you started working here since last month.";
	std::cout << std::endl;
}

void Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now.";
	std::cout << std::endl;
}


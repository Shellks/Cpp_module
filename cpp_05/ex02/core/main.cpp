/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:42:18 by acarlott          #+#    #+#             */
/*   Updated: 2023/12/11 23:40:43 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"

int main(void)
{
	{
		std::cout << "-------------------------------------------" << std::endl;
		std::cout << YELLOW << "ROTOMY REQUEST FORM TEST: " << RESET << std::endl;
		try
		{
			// AForm tooHigh("Chomage", -10, 1);
		}
		catch (std::exception &e)
		{
			std::cout << RED << "error: Form init: " << e.what() << RESET << std::endl;
		}
		try
		{
			// AForm tooLow("49_3", 160, 1);
		}
		catch (std::exception &e)
		{
			std::cout << RED << "error: Form init: " << e.what() << RESET << std::endl;
		}
		std::cout << "-------------------------------------------" << std::endl;
	}
	{
		std::cout << "-------------------------------------------" << std::endl;
		std::cout << YELLOW << "PRESIDENTIAL PARDON FORM TEST: " << RESET << std::endl;
		try
		{
			// AForm tooHigh("Chomage", -10, 1);
		}
		catch (std::exception &e)
		{
			std::cout << RED << "error: Form init: " << e.what() << RESET << std::endl;
		}
		try
		{
			// AForm tooLow("49_3", 160, 1);
		}
		catch (std::exception &e)
		{
			std::cout << RED << "error: Form init: " << e.what() << RESET << std::endl;
		}
		std::cout << "-------------------------------------------" << std::endl;
	}
	{
		std::cout << "-------------------------------------------" << std::endl;
		std::cout << YELLOW << "SHRUBERRY CREATION FORM TEST: " << RESET << std::endl;
		try
		{
			// AForm tooHigh("Chomage", -10, 1);
		}
		catch (std::exception &e)
		{
			std::cout << RED << "error: Form init: " << e.what() << RESET << std::endl;
		}
		try
		{
			// AForm tooLow("49_3", 160, 1);
		}
		catch (std::exception &e)
		{
			std::cout << RED << "error: Form init: " << e.what() << RESET << std::endl;
		}
		std::cout << "-------------------------------------------" << std::endl;
	}
}
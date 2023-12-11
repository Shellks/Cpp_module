/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:42:18 by acarlott          #+#    #+#             */
/*   Updated: 2023/12/11 23:20:11 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

int main(void)
{
	{
		std::cout << "-------------------------------------------" << std::endl;
		std::cout << YELLOW << "FORM TEST: TOO HIGH/LOW INIT FORM EXCEPTION" << RESET << std::endl;
		try
		{
			Form tooHigh("Chomage", -10, 1);
		}
		catch (std::exception &e)
		{
			std::cout << RED << "error: Form init: " << e.what() << RESET << std::endl;
		}
		try
		{
			Form tooLow("49_3", 160, 1);
		}
		catch (std::exception &e)
		{
			std::cout << RED << "error: Form init: " << e.what() << RESET << std::endl;
		}
		std::cout << "-------------------------------------------" << std::endl;
	}
	{
		std::cout << "-------------------------------------------" << std::endl;
		std::cout << YELLOW << "FORM TEST: TOO LOW SIGNED REQUEST" << RESET << std::endl;
		try
		{
			Form chomage("Chomage", 30, 1);
			Form form("49_3", 20, 1);
			Bureaucrat bender("bender", 25);
			std::cout << bender << std::endl;
			std::cout << chomage << std::endl;
			std::cout << form << std::endl;
			bender.signForm(chomage);
			bender.signForm(form);
			std::cout << chomage << std::endl;
			std::cout << form << std::endl;
		}
		catch (const Bureaucrat::GradeTooLowException &e)
		{
			std::cout << RED << "error: Bureaucrat init: " << e.what() << RESET << std::endl;
		}
		catch (const Bureaucrat::GradeTooHighException &e)
		{
			std::cout << RED << "error: Bureaucrat init: " << e.what() << RESET << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << RED << "error: Form init: " << e.what() << RESET << std::endl;
		}
		std::cout << "-------------------------------------------" << std::endl;
	}
}
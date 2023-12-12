/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:42:18 by acarlott          #+#    #+#             */
/*   Updated: 2023/12/12 19:56:02 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/Intern.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

int main(void)
{
	{
		std::cout << "-------------------------------------------" << std::endl;
		std::cout << YELLOW << "INTERN PRESIDENTIAL FORM TEST: " << RESET << std::endl;
		std::cout << std::endl;
		try
		{
			Bureaucrat cartman("cartman", 5);
			Intern randomIntern;
			AForm *form;

			form = randomIntern.makeForm("presidential pardon", "bender");
			std::cout << *form << std::endl;
			cartman.executeForm(*form);
			cartman.signForm(*form);
			cartman.executeForm(*form);
			delete form;
		}
		catch (std::exception &e)
		{
			std::cout << RED << "error: Form init: " << e.what() << RESET << std::endl;
		}
		std::cout << "-------------------------------------------" << std::endl;
	}
	{
		std::cout << "-------------------------------------------" << std::endl;
		std::cout << YELLOW << "INTERN ROBOTOMY FORM TEST: " << RESET << std::endl;
		std::cout << std::endl;
		try
		{
			Bureaucrat cartman("cartman", 5);
			Intern randomIntern;
			AForm *form;

			form = randomIntern.makeForm("robotomy request", "bender");
			std::cout << *form << std::endl;
			cartman.executeForm(*form);
			cartman.signForm(*form);
			cartman.executeForm(*form);
			delete form;
		}
		catch (std::exception &e)
		{
			std::cout << RED << "error: Form init: " << e.what() << RESET << std::endl;
		}
		std::cout << "-------------------------------------------" << std::endl;
	}
	{
		std::cout << "-------------------------------------------" << std::endl;
		std::cout << YELLOW << "INTERN SHRUBBERY FORM TEST: " << RESET << std::endl;
		std::cout << std::endl;
		try
		{
			Bureaucrat cartman("cartman", 5);
			Intern randomIntern;
			AForm *form;

			form = randomIntern.makeForm("shrubbery creation", "bender");
			std::cout << *form << std::endl;
			cartman.executeForm(*form);
			cartman.signForm(*form);
			cartman.executeForm(*form);
			delete form;
		}
		catch (std::exception &e)
		{
			std::cout << RED << "error: Form init: " << e.what() << RESET << std::endl;
		}
		std::cout << "-------------------------------------------" << std::endl;
	}
	{
		std::cout << "-------------------------------------------" << std::endl;
		std::cout << YELLOW << "INTERN BAD FORM TEST: " << RESET << std::endl;
		std::cout << std::endl;
		try
		{
			Bureaucrat cartman("cartman", 5);
			Intern randomIntern;
			AForm *form;

			form = randomIntern.makeForm("Bad form", "bender");
			if (!form)
				return (1);
			std::cout << *form << std::endl;
			cartman.executeForm(*form);
			cartman.signForm(*form);
			cartman.executeForm(*form);
			delete form;
		}
		catch (std::exception &e)
		{
			std::cout << RED << "error: " << e.what() << RESET << std::endl;
		}
		std::cout << "-------------------------------------------" << std::endl;
	}
}
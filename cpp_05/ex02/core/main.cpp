/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:42:18 by acarlott          #+#    #+#             */
/*   Updated: 2023/12/12 16:17:07 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

int main(void)
{
	// 						PRESIDENTIAL TEST OK
	// {
	// 	std::cout << "-------------------------------------------" << std::endl;
	// 	std::cout << YELLOW << "PRESIDENTIAL PARDON FORM TEST: " << RESET << std::endl;
	// 	std::cout << std::endl;
	// 	try
	// 	{
	// 		PresidentialPardonForm Pform("Macron");
	// 		Bureaucrat bender("bender", 24);
	// 		std::cout << bender << std::endl;
	// 		std::cout << Pform << std::endl;
	// 		Pform.execute(bender);
	// 		bender.signForm(Pform);
	// 		std::cout << Pform << std::endl;
	// 		Pform.execute(bender);
	// 		Bureaucrat PDGbender("PDGbender", 1);
	// 		std::cout << PDGbender << std::endl;
	// 		Pform.execute(PDGbender);
	// 		std::cout << std::endl;
	// 		std::cout << YELLOW << "PresidentialPardonForm copy test :" << RESET << std::endl;
	// 		std::cout << std::endl;
	// 		PresidentialPardonForm Pform2(Pform);
	// 		std::cout << Pform2 << std::endl;
	// 	}
	// 	catch (std::exception &e)
	// 	{
	// 		std::cout << RED << "error: Form init: " << e.what() << RESET << std::endl;
	// 	}
	// 	std::cout << "-------------------------------------------" << std::endl;
	// }
	//							ROBOTOMY TEST OK
	// {
	// 	std::cout << "-------------------------------------------" << std::endl;
	// 	std::cout << YELLOW << "ROBOTOMY REQUEST FORM TEST: " << RESET << std::endl;
	// std::cout << std::endl;
	// try
	// {
	// 	RobotomyRequestForm Pform("Cartman");
	// 	Bureaucrat bender("bender", 72);
	// 	std::cout << bender << std::endl;
	// 	std::cout << Pform << std::endl;
	// 	Pform.execute(bender);
	// 	bender.signForm(Pform);
	// 	std::cout << Pform << std::endl;
	// 	Pform.execute(bender);
	// 	Bureaucrat PDGbender("PDGbender", 1);
	// 	std::cout << PDGbender << std::endl;
	// 	Pform.execute(PDGbender);
	// 	std::cout << std::endl;
	// 	std::cout << YELLOW << "RobotomyRequestForm copy test :" << RESET << std::endl;
	// 	std::cout << std::endl;
	// 	RobotomyRequestForm Pform2(Pform);
	// 	std::cout << Pform2 << std::endl;
	// }
	// catch (std::exception &e)
	// {
	// 	std::cout << RED << "error: Form init: " << e.what() << RESET << std::endl;
	// }
	// 	std::cout << "-------------------------------------------" << std::endl;
	// }
	//							SHRUBBERY TEST OK
	{
		std::cout << "-------------------------------------------" << std::endl;
		std::cout << YELLOW << "SHRUBERRY CREATION FORM TEST: " << RESET << std::endl;
		std::cout << std::endl;
		try
		{
			ShrubberyCreationForm Pform("Cartman");
			Bureaucrat bender("bender", 145);
			std::cout << bender << std::endl;
			std::cout << Pform << std::endl;
			bender.executeForm(Pform);
			bender.signForm(Pform);
			std::cout << Pform << std::endl;
			bender.executeForm(Pform);
			Bureaucrat PDGbender("PDGbender", 1);
			std::cout << PDGbender << std::endl;
			PDGbender.executeForm(Pform);
			std::cout << std::endl;
			std::cout << YELLOW << "ShrubberyCreationForm copy test :" << RESET << std::endl;
			std::cout << std::endl;
			ShrubberyCreationForm Pform2(Pform);
			std::cout << Pform2 << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << RED << "error: Form init: " << e.what() << RESET << std::endl;
		}
		std::cout << "-------------------------------------------" << std::endl;
	}
}
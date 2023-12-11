/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:42:18 by acarlott          #+#    #+#             */
/*   Updated: 2023/12/11 17:34:20 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

int main(void)
{
	{
		std::cout << "-------------------------------------------" << std::endl;
		std::cout << YELLOW << "TOO HIGH INIT EXPECTION TEST:" << RESET << std::endl;
		std::cout << std::endl;
		try
		{
			std::cout << "Trying to hired a Bureaucrat with grade: " << BLUE << "-1" << RESET << std::endl;
			Bureaucrat tooHighInit("alex", -1);
		}
		catch (std::exception &e)
		{
			std::cout << RED << e.what() << RESET << std::endl;
		}
		std::cout << "-------------------------------------------" << std::endl;
		std::cout << YELLOW << "TOO HIGH INCREMENT EXPECTION TEST:" << RESET << std::endl;
		std::cout << std::endl;
		try
		{
			Bureaucrat tooHighInc("alex", 1);
			std::cout << tooHighInc << std::endl;
			std::cout << YELLOW << "Trying to increment grade.. " << RESET << std::endl;
			tooHighInc.incrementGrade();
		}
		catch (std::exception &e)
		{
			std::cout << RED << e.what() << RESET << std::endl;
		}
		std::cout << "-------------------------------------------" << std::endl;
	}
	{
		std::cout << "-------------------------------------------" << std::endl;
		std::cout << YELLOW << "TOO LOW INIT EXPECTION TEST:" << RESET << std::endl;
		std::cout << std::endl;
		try
		{
			std::cout << "Trying to hired a Bureaucrat with grade: " << BLUE << "151" << RESET << std::endl;
			Bureaucrat tooLowInit("alex", 151);
		}
		catch (std::exception &e)
		{
			std::cout << RED << e.what() << RESET << std::endl;
		}
		std::cout << "-------------------------------------------" << std::endl;
		std::cout << YELLOW << "TOO LOW INCREMENT EXPECTION TEST:" << RESET << std::endl;
		std::cout << std::endl;
		try
		{
			Bureaucrat tooLowInc("alex", 150);
			std::cout << tooLowInc << std::endl;
			std::cout << YELLOW << "Trying to decrement grade.. " << RESET << std::endl;
			tooLowInc.decrementGrade();
		}
		catch (std::exception &e)
		{
			std::cout << RED << e.what() << RESET << std::endl;
		}
		std::cout << "-------------------------------------------" << std::endl;
	}
	{
		std::cout << YELLOW << "GOOD GRADE TEST:" << RESET << std::endl;
		std::cout << std::endl;
		try
		{
			Bureaucrat goodGrade("alex", 50);
			std::cout << goodGrade << std::endl;
			std::cout << YELLOW << "Trying to decrement grade.. " << RESET << std::endl;
			goodGrade.decrementGrade();
			std::cout << goodGrade << std::endl;
			std::cout << YELLOW << "Trying to increment grade.. " << RESET << std::endl;
			goodGrade.incrementGrade();
			std::cout << goodGrade << std::endl;
			Bureaucrat goodGradeCopy(goodGrade);
			std::cout << goodGradeCopy << std::endl;
			std::cout << YELLOW << "Trying to increment grade.. " << RESET << std::endl;
			goodGrade.incrementGrade();
			std::cout << goodGrade << std::endl;
			std::cout << goodGradeCopy << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << RED << e.what() << RESET << std::endl;
		}
		std::cout << "-------------------------------------------" << std::endl;
	}
}
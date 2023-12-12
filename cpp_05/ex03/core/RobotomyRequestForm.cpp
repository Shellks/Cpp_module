/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:05:38 by acarlott          #+#    #+#             */
/*   Updated: 2023/12/12 16:04:47 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
	std::cout << "Form " << YELLOW << this->getName() << RESET << " was " << GREEN << "created" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "Form " << YELLOW << this->getName() << RESET << " was " << GREEN << "created" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : AForm(src), _target(src._target)
{
	std::cout << "Form " << YELLOW << src.getName() << RESET << " was " << GREEN << "copied " << RESET << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/
RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &src)
{
	(void)src;
	return *this;
}
std::ostream &operator<<(std::ostream &out, RobotomyRequestForm const &src)
{
	out << "Form " << YELLOW << src.getName() << RESET << ":" << std::endl;
	if (src.isSigned() == false)
		out << "	- isSigned: " << RED << std::boolalpha << src.isSigned() << RESET << std::endl;
	else
		out << "	- isSigned: " << GREEN << std::boolalpha << src.isSigned() << RESET << std::endl;
	out << "	- require grade to sign: " << GREEN << src.getGradeToSign() << RESET << std::endl;
	out << "	- require grade to execute: " << GREEN << src.getGradeToExecute() << RESET;
	return (out);
}
/*
** --------------------------------- METHODS ----------------------------------
*/

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	std::time_t time = std::time(NULL);
	std::tm *time_info = localtime(&time);
	if (this->isSigned() == false)
		throw(AForm::IsNotSignedException());
	else if (executor.getGrade() > this->getGradeToExecute())
		throw(AForm::GradeTooLowException());
	std::cout << "Vrrrrrr... Clank! Clank! Vrrrrrr..." << std::endl;
	if (time_info->tm_sec % 2 == 0)
		std::cout << BLUE << "Robotomy: " << GREEN << "succes! " << YELLOW << this->_target << RESET << " has just been robotomized to a state-of-the-art robot." << std::endl;
	else
		std::cout << BLUE << "Robotomy: " << RED << "failure! " << YELLOW << this->_target << RESET << " still a human in a low-tech cave." << std::endl;
}
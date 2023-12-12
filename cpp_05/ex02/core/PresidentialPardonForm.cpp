/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:16:05 by acarlott          #+#    #+#             */
/*   Updated: 2023/12/12 16:08:29 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("Random")
{
	std::cout << "Form " << YELLOW << this->getName() << RESET << " was " << GREEN << "created" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "Form " << YELLOW << this->getName() << RESET << " was " << GREEN << "created" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : AForm(src), _target(src._target)
{
	std::cout << "Form " << YELLOW << src.getName() << RESET << " was " << GREEN << "copied " << RESET << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/
PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &src)
{
	(void)src;
	return *this;
}
std::ostream &operator<<(std::ostream &out, PresidentialPardonForm const &src)
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

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (this->isSigned() == false)
		throw(AForm::IsNotSignedException());
	else if (executor.getGrade() > this->getGradeToExecute())
		throw(AForm::GradeTooLowException());
	std::cout << "Target " << YELLOW << this->_target << RESET << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

/*
** ----------------------------------------------------------------------------
*/
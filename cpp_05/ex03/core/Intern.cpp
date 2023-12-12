/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:00:59 by acarlott          #+#    #+#             */
/*   Updated: 2023/12/12 19:27:41 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"

Intern::Intern()
{
}

Intern::Intern(Intern const &src)
{
	(void)src;
}

Intern::~Intern()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/
Intern &Intern::operator=(Intern const &src)
{
	(void)src;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/
static AForm *makeRobotomyRequest(std::string const &target)
{
	return (new RobotomyRequestForm(target));
}

static AForm *makeShrubberyRequest(std::string const &target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm *makePresidentialRequest(std::string const &target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(std::string const &formName, std::string const &target) const
{
	AForm *(*form[3])(std::string const &) = {makePresidentialRequest, makeRobotomyRequest, makeShrubberyRequest};
	std::string const name[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};

	for (int i = 0; i < 3; i++)
	{
		if (!name[i].compare(formName))
		{
			std::cout << "Intern " << GREEN << "creates " << YELLOW << name[i] << RESET << " form" << std::endl;
			return (form[i](target));
		}
	}
	std::cout << "Intern " << RED << "can't creates " << YELLOW << formName << RESET << " form" << std::endl;
	return (NULL);
}

/*
** ----------------------------------------------------------------------------
*/

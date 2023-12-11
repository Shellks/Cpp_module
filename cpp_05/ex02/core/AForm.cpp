/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:58:49 by acarlott          #+#    #+#             */
/*   Updated: 2023/12/11 23:33:50 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"

AForm::AForm() : _name("Random_AForm"), _gradeToSign(150), _gradeToExecute(150), _Signed(false)
{
	std::cout << "AForm " << YELLOW << this->_name << RESET << " was " << GREEN << "created" << RESET << std::endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _Signed(false)
{
	if (this->_gradeToSign < 1 || this->_gradeToExecute < 1)
		throw(AForm::GradeTooHighException());
	else if (this->_gradeToSign > 150 || this->_gradeToExecute > 150)
		throw(AForm::GradeTooLowException());
	std::cout << "AForm " << YELLOW << this->_name << RESET << " was " << GREEN << "created" << RESET << std::endl;
}

AForm::AForm(AForm const &src) : _name(src._name + "Copy"), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute), _Signed(false)
{
	std::cout << "AForm " << YELLOW << this->_name << RESET << " was " << GREEN << "creat " << RESET << "with " << YELLOW << src._name << RESET << " Aform" << std::endl;
}

AForm::~AForm()
{
	// std::cout << "AForm " << YELLOW << this->_name << RESET << " was " << RED "fired" << RESET << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/
AForm &AForm::operator=(AForm const &src)
{
	(void)src;
	return *this;
}
std::ostream &operator<<(std::ostream &out, AForm const &src)
{
	out << "AForm " << YELLOW << src.getName() << RESET << ":" << std::endl;
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

void AForm::beSigned(Bureaucrat const &crat)
{
	if (this->_gradeToSign >= crat.getGrade())
		this->_Signed = true;
	else
		throw(AForm::GradeTooLowException());
}

std::string const AForm::getName(void) const
{
	return (this->_name);
}
int AForm::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}
int AForm::getGradeToExecute(void) const
{
	return (this->_gradeToExecute);
}
bool AForm::isSigned(void) const
{
	return (this->_Signed);
}

/*
** --------------------------------- EXCEPTION ----------------------------------
*/
const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}
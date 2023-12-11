/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:58:49 by acarlott          #+#    #+#             */
/*   Updated: 2023/12/11 22:48:54 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"

Form::Form() : _name("Random_Form"), _gradeToSign(150), _gradeToExecute(150), _Signed(false)
{
	std::cout << "Form " << YELLOW << this->_name << RESET << " was " << GREEN << "created" << RESET << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _Signed(false)
{
	if (this->_gradeToSign < 1 || this->_gradeToExecute < 1)
		throw(Form::GradeTooHighException());
	else if (this->_gradeToSign > 150 || this->_gradeToExecute > 150)
		throw(Form::GradeTooLowException());
	std::cout << "Form " << YELLOW << this->_name << RESET << " was " << GREEN << "created" << RESET << std::endl;
}

Form::Form(Form const &src) : _name(src._name + "Copy"), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute), _Signed(false)
{
	std::cout << "Form " << YELLOW << this->_name << RESET << " was " << GREEN << "creat " << RESET << "with " << YELLOW << src._name << RESET << " form" << std::endl;
}

Form::~Form()
{
	// std::cout << "Form " << YELLOW << this->_name << RESET << " was " << RED "fired" << RESET << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/
Form &Form::operator=(Form const &src)
{
	(void)src;
	return *this;
}
std::ostream &operator<<(std::ostream &out, Form const &src)
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

void Form::beSigned(Bureaucrat const &crat)
{
	if (this->_gradeToSign >= crat.getGrade())
		this->_Signed = true;
	else
		throw(Form::GradeTooLowException());
}

std::string const Form::getName(void) const
{
	return (this->_name);
}
int Form::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}
int Form::getGradeToExecute(void) const
{
	return (this->_gradeToExecute);
}
bool Form::isSigned(void) const
{
	return (this->_Signed);
}

/*
** --------------------------------- EXCEPTION ----------------------------------
*/
const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}
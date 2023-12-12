/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:51:18 by acarlott          #+#    #+#             */
/*   Updated: 2023/12/12 19:43:40 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR/DESTRUCTOR--------------------------------
*/
Bureaucrat::Bureaucrat() : _name("Random_bureaucrat"), _grade(150)
{
	std::cout << "Bureaucrat " << YELLOW << this->_name << RESET << " was " << GREEN << "hired" << RESET << std::endl;
	// std::cout << "his current grade is: " << BLUE << this->_grade << RESET << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw(Bureaucrat::GradeTooHighException());
	else if (grade > 150)
		throw(Bureaucrat::GradeTooLowException());
	this->_grade = grade;
	std::cout << "Bureaucrat " << YELLOW << this->_name << RESET << " was " << GREEN << "hired" << RESET << std::endl;
	// std::cout << "his current grade is: " << BLUE << this->_grade << RESET << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src.getName() + "Copy")
{
	*this = src;
	std::cout << "Bureaucrat " << YELLOW << this->_name << RESET << " was " << GREEN << "hired " << RESET << "with " << YELLOW << src._name << RESET << " current grade: " << BLUE << src.getGrade() << RESET << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	// std::cout << "Bureaucrat " << YELLOW << this->_name << RESET << " was " << RED "fired" << RESET << std::endl;
	// std::cout << "Their grade was: " << BLUE << this->_grade << RESET << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/
Bureaucrat &Bureaucrat::operator=(Bureaucrat const &src)
{
	if (this != &src)
		this->_grade = src._grade;
	return *this;
}
std::ostream &operator<<(std::ostream &out, Bureaucrat const &src)
{
	out << YELLOW << src.getName() << RESET << ", bureaucrat grade: " << BLUE << src.getGrade() << RESET;
	return (out);
}
/*
** --------------------------------- METHODS ----------------------------------
*/

void Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute(*this);
		std::cout << "Bureaucrat " << YELLOW << this->_name << GREEN << " executed " << YELLOW << form.getName() << RESET << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Bureaucrat " << YELLOW << this->getName() << RESET << " couldn't execute " << YELLOW << form.getName() << RESET << " because " << RED << e.what() << RESET << std::endl;
	}
}

void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << "Bureaucrat " << YELLOW << this->_name << GREEN << " signed " << YELLOW << form.getName() << RESET << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Bureaucrat " << YELLOW << this->_name << RESET << " couldn't sign " << YELLOW << form.getName() << RESET << " because " << RED << e.what() << RESET << std::endl;
		return;
	}
}

std::string Bureaucrat::getName() const
{
	return (this->_name);
}
int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::incrementGrade(void)
{
	this->_grade--;
	if (this->_grade < 1)
	{
		this->_grade++;
		throw(Bureaucrat::GradeTooHighException());
	}
}
void Bureaucrat::decrementGrade(void)
{
	this->_grade++;
	if (this->_grade > 150)
	{
		this->_grade--;
		throw(Bureaucrat::GradeTooLowException());
	}
}
/*
** --------------------------------- EXCEPTION ----------------------------------
*/
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high: Max grade is '1' ");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low: Max grade is '150' ");
}
/* ************************************************************************** */

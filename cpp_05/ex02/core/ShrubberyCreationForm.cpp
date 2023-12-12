/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:14:34 by acarlott          #+#    #+#             */
/*   Updated: 2023/12/12 16:12:23 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout << "Form " << YELLOW << this->getName() << RESET << " was " << GREEN << "created" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "Form " << YELLOW << this->getName() << RESET << " was " << GREEN << "created" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : AForm(src), _target(src._target)
{
	std::cout << "Form " << YELLOW << src.getName() << RESET << " was " << GREEN << "copied " << RESET << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/
ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src)
{
	(void)src;
	return *this;
}
std::ostream &operator<<(std::ostream &out, ShrubberyCreationForm const &src)
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

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (this->isSigned() == false)
		throw(AForm::IsNotSignedException());
	else if (executor.getGrade() > this->getGradeToExecute())
		throw(AForm::GradeTooLowException());
	std::string filename = this->_target + "_shrubbery";
	std::ofstream ofs(filename.c_str());
	if (ofs.is_open())
	{
		ofs << "			                     ___ " << std::endl;
		ofs << "                _,-'\"\"   \"\"\"\"`--. " << std::endl;
		ofs << "             ,-'          __,,--  " << std::endl;
		ofs << "           ,'    __,--\"\"\"\"dF      ) " << std::endl;
		ofs << "          /   .-\"Hb_,--\"\"dF      / " << std::endl;
		ofs << "        ,'       _Hb ___dF\"-._,-' / " << std::endl;
		ofs << "      ,'      _,-\"\"\"\"   \"\"--..__ " << std::endl;
		ofs << "     (     ,-'                  `. " << std::endl;
		ofs << "      `._,'     _   _             ; " << std::endl;
		ofs << "       ,'     ,' `-'Hb-.___..._,-' " << std::endl;
		ofs << "       |    ,'\"Hb.-'HH`-.dHF\" " << std::endl;
		ofs << "        `--'   \"Hb  HH  dF\" " << std::endl;
		ofs << "                \"Hb HH dF " << std::endl;
		ofs << "                 \"HbHHdF " << std::endl;
		ofs << "                  |HHHF " << std::endl;
		ofs << "                  |HHH| " << std::endl;
		ofs << "                  |HHH| " << std::endl;
		ofs << "                  |HHH| " << std::endl;
		ofs << "                  |HHH| " << std::endl;
		ofs << "                  dHHHb " << std::endl;
		ofs << "                .dFd|bHb.               o " << std::endl;
		ofs << "      o       .dHFdH|HbTHb.          o / " << std::endl;
		ofs << "|  Y  |  |__,dHHFdHH|HHhoHHb.       Y " << std::endl;
		ofs << "########################################## " << std::endl;
		ofs.close();
		std::cout << "File '" << YELLOW << filename << RESET << "'" << GREEN << " created " RESET << std::endl;
	}
	else
		throw(ShrubberyCreationForm::FileNotOpenException());
}

/*
** --------------------------------- EXCEPTION ----------------------------------
*/

const char *ShrubberyCreationForm::FileNotOpenException::what() const throw()
{
	return ("Unable to open the file for writing.");
}
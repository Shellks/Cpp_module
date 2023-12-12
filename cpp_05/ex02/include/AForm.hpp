/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:51:05 by acarlott          #+#    #+#             */
/*   Updated: 2023/12/12 16:01:58 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#define RESET "\033[0m"
#define BROWN "\033[0;33m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	std::string const _name;
	int const _gradeToSign;
	int const _gradeToExecute;
	bool _Signed;

public:
	AForm();
	AForm(std::string name, int gradeToSign, int gradeToExecute);
	AForm(AForm const &src);
	virtual ~AForm();

	std::string const getName(void) const;
	int getGradeToSign(void) const;
	int getGradeToExecute(void) const;
	bool isSigned(void) const;
	void beSigned(Bureaucrat const &crat);
	virtual void execute(Bureaucrat const &executor) const = 0;

	AForm &operator=(AForm const &src);

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class IsNotSignedException : public std::exception
	{
	public:
		virtual const char *what(void) const throw();
	};
	class IsSignedException : public std::exception
	{
	public:
		virtual const char *what(void) const throw();
	};
};

std::ostream &operator<<(std::ostream &out, AForm const &src);

#endif
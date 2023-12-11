/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:51:05 by acarlott          #+#    #+#             */
/*   Updated: 2023/12/11 20:09:43 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#define RESET "\033[0m"
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	std::string const _name;
	int const _gradeToSign;
	int const _gradeToExecute;
	bool _Signed;

public:
	Form();
	Form(std::string name, int gradeToSign, int gradeToExecute);
	Form(Form const &src);
	~Form();

	std::string const getName(void) const;
	int getGradeToSign(void) const;
	int getGradeToExecute(void) const;
	bool isSigned(void) const;
	void beSigned(Bureaucrat const &crat);

	Form &operator=(Form const &src);

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
};
std::ostream &operator<<(std::ostream &out, Form const &src);

#endif
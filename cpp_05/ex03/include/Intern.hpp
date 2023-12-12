/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:54:39 by acarlott          #+#    #+#             */
/*   Updated: 2023/12/12 19:53:27 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Intern
{
public:
	Intern();
	Intern(Intern const &src);
	~Intern();

	AForm *makeForm(std::string const &formName, std::string const &target) const;

	Intern &operator=(Intern const &src);
};

#endif
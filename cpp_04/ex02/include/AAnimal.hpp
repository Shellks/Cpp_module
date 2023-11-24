/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:55:00 by acarlott          #+#    #+#             */
/*   Updated: 2023/11/23 17:46:21 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef AAnimal_HPP
#define AAnimal_HPP

#include <iostream>
#include <string>
#include "Brain.hpp"

class AAnimal
{
public:
	AAnimal();
	AAnimal(std::string const type_name);
	AAnimal(AAnimal const &src);
	virtual ~AAnimal();

	virtual AAnimal &operator=(AAnimal const &src);

	std::string getType(void) const;
	virtual void makeSound(void) const = 0;
	virtual Brain *getBrain(void) const = 0;

protected:
	std::string type;
};

#endif

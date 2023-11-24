/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:30:51 by acarlott          #+#    #+#             */
/*   Updated: 2023/11/24 10:25:35 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef WrongAnimal_HPP
#define WrongAnimal_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
public:
	WrongAnimal();
	WrongAnimal(std::string const type_name);
	WrongAnimal(WrongAnimal const &src);
	~WrongAnimal();

	WrongAnimal &operator=(WrongAnimal const &src);
	std::string getType(void) const;
	void makeSound(void) const;

protected:
	std::string type;
};

#endif

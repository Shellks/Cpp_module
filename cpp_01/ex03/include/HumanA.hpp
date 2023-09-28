/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:01:31 by acarlott          #+#    #+#             */
/*   Updated: 2023/09/28 20:31:47 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HumanA_HPP
#define HumanA_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanA
{
private:
	Weapon&		_Weapon;
	std::string	_name;

public:
	HumanA(std::string name, Weapon& club);
	~HumanA(void);

	void	attack(void) const;
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:02:28 by acarlott          #+#    #+#             */
/*   Updated: 2023/09/29 10:06:52 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HumanB_HPP
# define HumanB_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanB
{
private:
	std::string		_name;

public:
	HumanB(std::string name);
	~HumanB(void);
	Weapon*			_Weapon;

	void	attack(void) const;
	void	setWeapon(Weapon& club);
};

#endif
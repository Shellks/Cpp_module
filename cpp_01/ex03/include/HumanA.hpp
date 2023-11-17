/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:01:31 by acarlott          #+#    #+#             */
/*   Updated: 2023/11/17 09:11:54 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HumanA_HPP
# define HumanA_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanA
{
	private:
		std::string	_name;
		Weapon&		_Weapon;

	public:
		HumanA(std::string name, Weapon& club);
		~HumanA(void);

		void	attack(void) const;
};

#endif

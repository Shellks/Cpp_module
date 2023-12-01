/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:41:48 by acarlott          #+#    #+#             */
/*   Updated: 2023/12/01 13:25:21 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"

static	bool	isdead(ScavTrap* scav, ClapTrap* bandit) {
	if (scav->getHitPoints() == 0 || bandit->getHitPoints() == 0)
		return true;
	return false;
}

int	main(void) 
{
	ScavTrap	scav("Scavington");
	ClapTrap	bandit("Pandora bandit");

	bandit.setAttackDamage(4);
	scav.guardGate();
	while (scav.getEnergyPoints() && bandit.getEnergyPoints())
	{
		bandit.berepaired(15);
		scav.attack(bandit.getName());
		bandit.takedamage(scav.getAttackDamage());
		if (isdead(&scav, &bandit) == true)
			break ;
		bandit.attack(scav.getName());
		scav.takedamage(bandit.getAttackDamage());
		if (isdead(&scav, &bandit) == true)
			break ;
		scav.berepaired(10);
	}
	ScavTrap	rivalscav(scav);
	rivalscav.attack(scav.getName());
	return 0;
}

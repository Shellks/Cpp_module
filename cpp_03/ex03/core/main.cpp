/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:41:48 by acarlott          #+#    #+#             */
/*   Updated: 2023/10/06 16:28:35 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"
#include "../include/FragTrap.hpp"

static	bool	isdead(ScavTrap* scav, ClapTrap* bandit) {
	if (scav->getHitPoints() == 0 || bandit->getHitPoints() == 0)
		return true;
	return false;
}

int	main(void) 
{
	ScavTrap	scav("SC4V-TP");
	FragTrap	frag("FR4G-TP");

	scav.guardGate();
	while (scav.getEnergyPoints() != 0 || frag.getEnergyPoints() != 0) {
		scav.attack(frag.getName());
		frag.takedamage(scav.getAttackDamage());
		if (isdead(&scav, &frag) == true)
			break ;
		frag.berepaired(10);
		frag.attack(scav.getName());
		scav.takedamage(frag.getAttackDamage());
		if (isdead(&scav, &frag) == true)
			break ;
		scav.berepaired(10);
	}
	frag.highFivesGuys();
	return 0;
}
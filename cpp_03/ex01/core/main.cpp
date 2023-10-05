/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:41:48 by acarlott          #+#    #+#             */
/*   Updated: 2023/10/05 20:15:54 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

int	main(void) 
{
	ClapTrap	clap("CL4P-TP");
	ClapTrap	bandit("Pandora bandit");

	bandit.setAttackDamage(4);
	while ((clap.getHitPoints() != 0 && bandit.getHitPoints() != 0)) {
		clap.attack(bandit.getName());
		bandit.takedamage(clap.getAttackDamage());
		bandit.attack(clap.getName());
		clap.takedamage(bandit.getAttackDamage());
		clap.berepaired(4);
		if (clap.getEnergyPoints() == 0 && bandit.getEnergyPoints() == 0)
			break ;
	}
	return 0;
}
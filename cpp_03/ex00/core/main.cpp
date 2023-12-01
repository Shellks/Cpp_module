/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:41:48 by acarlott          #+#    #+#             */
/*   Updated: 2023/12/01 13:19:21 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

int	main(void) 
{
	ClapTrap	clap("CL4P-TP");
	ClapTrap	bandit("Pandora bandit");

	bandit.setAttackDamage(3);
	while ((clap.getHitPoints() != 0 && bandit.getHitPoints() != 0))
	{
		clap.attack(bandit.getName());
		bandit.takedamage(clap.getAttackDamage());
		bandit.attack(clap.getName());
		clap.takedamage(bandit.getAttackDamage());
		clap.berepaired(2);
		if (clap.getEnergyPoints() == 0 && bandit.getEnergyPoints() == 0)
			break ;
	}
	ClapTrap	rivalBandit(bandit);
	rivalBandit.attack(clap.getName());
	return 0;
}

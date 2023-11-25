/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:52:09 by acarlott          #+#    #+#             */
/*   Updated: 2023/11/25 10:59:54 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Character.hpp"
#include "../include/ICharacter.hpp"
#include "../include/Ice.hpp"
#include "../include/Cure.hpp"
#include "../include/AMateria.hpp"

int main(void)
{
	Character *Rogue = new Character("Rogue");
	AMateria *ice = new Ice();
	AMateria *cure = new Cure();

	Rogue->equip(ice);
	Rogue->equip(cure);
	Rogue->equip(ice->clone());
	delete (Rogue);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:52:09 by acarlott          #+#    #+#             */
/*   Updated: 2023/11/25 20:27:23 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Character.hpp"
#include "../include/ICharacter.hpp"
#include "../include/Ice.hpp"
#include "../include/Cure.hpp"
#include "../include/AMateria.hpp"
#include "../include/MateriaSource.hpp"

// int main(void)
// {
// 	ICharacter *Reaper = new Character("Reaper");
// 	ICharacter *Mage = new Character("Mage");
// 	AMateria *ice = new Ice();
// 	AMateria *cure = new Cure();

// 	Reaper->equip(ice);
// 	Reaper->equip(cure);
// 	Reaper->use(0, *Mage);
// 	Reaper->use(1, *Mage);
// 	// Reaper->use(2, *Mage);
// 	// Reaper->use(25, *Mage);
// 	Reaper->unequip(0);
// 	Reaper->unequip(1);
// 	delete (Reaper);
// 	delete (Mage);
// }

int main()
{
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter *me = new Character("me");
	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter *bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	return 0;
}

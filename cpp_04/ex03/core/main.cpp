/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:52:09 by acarlott          #+#    #+#             */
/*   Updated: 2023/12/13 13:59:14 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Character.hpp"
#include "../include/ICharacter.hpp"
#include "../include/Ice.hpp"
#include "../include/Cure.hpp"
#include "../include/AMateria.hpp"
#include "../include/MateriaSource.hpp"

int main(void)
{
	{
		std::cout << "	TEST 0 : Default test" << std::endl;
		std::cout << std::endl;
		IMateriaSource *src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter *Cloud = new Character("Cloud");
		AMateria *tmp;
		tmp = src->createMateria("ice");
		Cloud->equip(tmp);
		tmp = src->createMateria("cure");
		Cloud->equip(tmp);
		ICharacter *Sephiroth = new Character("Sephiroth");
		Cloud->use(0, *Sephiroth);
		Cloud->use(1, *Sephiroth);
		delete Sephiroth;
		delete Cloud;
		delete src;
	}
//						Test 0 : Pointer management
	// {
	// 	std::cout << "	TEST 0 : Pointer management" << std::endl;
	// 	std::cout << std::endl;
	// 	ICharacter *Cloud = new Character("Cloud");
	// 	IMateriaSource *src = new MateriaSource();
	// 	AMateria *test = new Ice();
	// 	src->learnMateria(new Cure());
	// 	src->learnMateria(test);
	// 	src->learnMateria(test);
	// 	Cloud->equip(test);
	// 	Cloud->equip(test);
	// 	Cloud->equip(src->createMateria("ice"));
	// 	Cloud->use(0, *Cloud);
	// 	Cloud->unequip(0);
	// 	Cloud->use(0, *Cloud);
	// 	delete (Cloud);
	// 	delete (src);
	// }
//						Test 1 : Inventory && Use management
	// {
	// 	std::cout << "	TEST : Inventory && Use management" << std::endl;
	// 	IMateriaSource *src = new MateriaSource();
	// 	ICharacter *Cloud = new Character("Cloud");
	// 	ICharacter *Sephiroth = new Character("Sephiroth");
	// 	int i = 0;
	// 	for (; i < 5; i++)
	// 		((i % 2 == 0) ? src->learnMateria(new Ice()) : src->learnMateria(new Cure()));
	// 	for (i = 0; i < 5; i++)
	// 		((i % 2 == 0) ? Cloud->equip(src->createMateria("ice")) : Cloud->equip(src->createMateria("cure")));
	// 	for (i = 0; i < 5; i++)
	// 		Cloud->use(i, *Sephiroth);
	// 	for (i = 0; i < 5; i++)
	// 		(Cloud->unequip(i));
	// 	for (i = 0; i < 2; i++)
	// 		(Cloud->unequip(i));
	// 	delete (Cloud);
	// 	delete (Sephiroth);
	// 	delete (src);
	// }
// //	Test 2 : Deep Copy
	// {
	// 	std::cout << "	TEST : DEEP COPY" << std::endl;
	// 	IMateriaSource *src = new MateriaSource();
	// 	Character *Cloud = new Character("Cloud");
	// 	Character *Sephiroth = new Character("Sephiroth");
	// 	int i = 0;
	// 	src->learnMateria(new Ice());
	// 	src->learnMateria(new Cure());
	// 	for (i = 0; i < 4; i++)
	// 	{
	// 		Cloud->equip(src->createMateria("ice"));
	// 		Sephiroth->equip(src->createMateria("cure"));
	// 	}
	// 	std::cout << "Genesis appears and copy Sephiroth inventory" << std::endl;
	// 	Character *Genesis = new Character(*Sephiroth);
	// 	std::cout << "Sephiroth copy Cloud inventory" << std::endl;
	// 	*Sephiroth = *Cloud;
	// 	for (i = 0; i < 4; i++)
	// 	{
	// 		Cloud->unequip(i);
	// 		Cloud->equip(src->createMateria("test"));
	// 	}
	// 	for (i = 0; i < 4; i++)
	// 	{
	// 		Genesis->use(0, *Cloud);
	// 		Sephiroth->use(i, *Cloud);
	// 		Cloud->use(i, *Sephiroth);
	// 	}
	// 	delete (Cloud);
	// 	delete (Sephiroth);
	// 	delete (Genesis);
	// 	delete (src);
	// }
}

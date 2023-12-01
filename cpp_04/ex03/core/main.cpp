/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:52:09 by acarlott          #+#    #+#             */
/*   Updated: 2023/12/01 15:35:54 by acarlott         ###   ########lyon.fr   */
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
	// {
	// 	IMateriaSource *src = new MateriaSource();
	// 	src->learnMateria(new Ice());
	// 	src->learnMateria(new Cure());
	// 	ICharacter *Cloud = new Character("Cloud");
	// 	AMateria *tmp;
	// 	tmp = src->createMateria("ice");
	// 	Cloud->equip(tmp);
	// 	tmp = src->createMateria("cure");
	// 	Cloud->equip(tmp);
	// 	ICharacter *Sephiroth = new Character("Sephiroth");
	// 	Cloud->use(0, *Sephiroth);
	// 	Cloud->use(1, *Sephiroth);
	// 	delete Sephiroth;
	// 	delete Cloud;
	// 	delete src;
	// 	return 0;
	// }
	// 					Test to debug !!!! : Pointer management
	{
		AMateria *test = new Ice();
		IMateriaSource *src = new MateriaSource();
		ICharacter *Cloud = new Character("Cloud");
		Cloud->equip(test);
		src->learnMateria(test);
		src->learnMateria(new Cure());
		std::cout << "the type of materia is : " << test->getType() << std::endl;
		Cloud->equip(test);
		Cloud->unequip(0);
		delete (Cloud);
		delete (src);
		// Segfault quand on assigne le meme pointeur d'instance AMateria a l'inventaire de materiasrc et celui du perso
		// on delete bien au 1er destructeur mais le second a toujours un pointeur valide bien que l'adresse associé soit delete.
	}
	// 					Test 1 : Inventory && Use management
	// {
	// 	std::cout << "	TEST : Inventory && Use management" << std::endl;
	// 	IMateriaSource *src = new MateriaSource();
	// 	ICharacter *Cloud = new Character("Cloud");
	// 	ICharacter *Sephiroth = new Character("Sephiroth");
	// 	int i = 0;
	// 	for (; i < 5; i++)
	// 		((i % 2 == 0) ? src->learnMateria(new Ice()) : src->learnMateria(new Cure()));
	// 	// Leak de materia quand l'inventaire est plein et qu'on veut add, le sujet nous demande de ne rien faire ducoup on gere comment la ?
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
	// Test 2 : Deep Copy
// 	{
// 		std::cout << "	TEST : DEEP COPY" << std::endl;
// 		IMateriaSource *src = new MateriaSource();
// 		Character *Cloud = new Character("Cloud");
// 		Character *Sephiroth = new Character("Sephiroth");
// 		int i = 0;

// 		src->learnMateria(new Ice());
// 		src->learnMateria(new Cure());
// 		for (i = 0; i < 4; i++)
// 		{
// 			Cloud->equip(src->createMateria("ice"));
// 			Sephiroth->equip(src->createMateria("cure"));
// 		}
// 		std::cout << "Genesis appears and copy Sephiroth inventory" << std::endl;
// 		Character *Genesis = new Character(*Sephiroth);
// 		std::cout << "Sephiroth copy Cloud inventory" << std::endl;
// 		*Sephiroth = *Cloud;
// 		for (i = 0; i < 4; i++)
// 		{
// 			Genesis->use(0, *Cloud);
// 			Sephiroth->use(i, *Cloud);
// 		}
// 		for (i = 0; i < 4; i++)
// 		{
// 			Cloud->unequip(i);
// 			Cloud->equip(src->createMateria("test"));
// 		}
// 		for (i = 0; i < 4; i++)
// 		{
// 			Cloud->use(i, *Sephiroth);
// 			Sephiroth->use(i, *Cloud);
// 			Genesis->use(i, *Cloud);
// 		}
// 		delete (Cloud);
// 		delete (Sephiroth);
// 		delete (Genesis);
// 		delete (src);
// 	}
}

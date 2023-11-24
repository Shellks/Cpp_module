/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:16:29 by acarlott          #+#    #+#             */
/*   Updated: 2023/11/24 10:38:03 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/WrongCat.hpp"

int main()
{
	// {
	// 	// Now AAnimal is abstract class so this can't work anymore
	// 	AAnimal test;
	// }
	{
		int x = 10;
		int i = 0;

		std::cout << "CREATING AAnimalS TAB:" << std::endl;
		AAnimal const *tab[x];
		for (; i < x; i++)
		{
			if (i < x / 2)
				tab[i] = new Dog();
			else
				tab[i] = new Cat();
		}
		std::cout << std::endl
				  << "TEST: FIRST HALF TAB IS DOG OTHER HALF IS CAT" << std::endl;
		for (i = 0; i < x; i++)
		{
			tab[i]->makeSound();
		}
		std::cout << std::endl
				  << "DELETING AAnimalS TAB:" << std::endl;
		for (i = 0; i < x; i++)
			delete tab[i];
	}
	{
		std::cout << std::endl
				  << "TESTING DEEP COPY:" << std::endl;
		AAnimal *dog = new Dog();
		AAnimal *cat = new Cat();
		dog->getBrain()->setIdeas(0, "Bacoon");
		cat->getBrain()->setIdeas(0, "Poissonn");
		std::cout << std::endl;
		std::cout << "dog have idea : " << dog->getBrain()->getIdeas(0) << std::endl;
		std::cout << "cat have idea : " << cat->getBrain()->getIdeas(0) << std::endl;
		std::cout << "Dog copy cat brain.." << std::endl;
		*dog = *cat;
		std::cout << "dog have idea : " << dog->getBrain()->getIdeas(0) << std::endl;
		std::cout << "cat have idea : " << cat->getBrain()->getIdeas(0) << std::endl;
		std::cout << "Cat set a new idea" << std::endl;
		cat->getBrain()->setIdeas(0, "Saumon miam !");
		std::cout << "dog have idea : " << dog->getBrain()->getIdeas(0) << std::endl;
		std::cout << "cat have idea : " << cat->getBrain()->getIdeas(0) << std::endl;
		std::cout << "A twin of the current dog appears !" << std::endl;
		AAnimal *twinDog = new Dog(*dog);
		std::cout << "twinDog have idea : " << twinDog->getBrain()->getIdeas(0) << std::endl;
		std::cout << "Dog set a new idea" << std::endl;
		dog->getBrain()->setIdeas(0, "want to become vegetarian..");
		std::cout << "dog have idea : " << dog->getBrain()->getIdeas(0) << std::endl;
		std::cout << "twinDog have idea : " << twinDog->getBrain()->getIdeas(0) << std::endl;
		std::cout << std::endl;
		delete (dog);
		delete (cat);
		delete (twinDog);
	}
	//								TEST: Default test
	// {
	// 	const AAnimal* meta = new AAnimal();
	// 	const AAnimal* j = new Dog();
	// 	const AAnimal* i = new Cat();
	// 	std::cout << meta->getType() << std::endl;
	// 	std::cout << j->getType() << std::endl;
	// 	std::cout << i->getType() << std::endl;
	// 	i->makeSound(); //will output the Cat sound!
	// 	j->makeSound(); //will output the Dog sound!
	// 	meta->makeSound(); //Will output the AAnimal sound!
	// 	delete meta;
	// 	delete j;
	// 	delete i;
	// }
	//								TEST: WrongAnimals
	// {
	// 	const WrongAnimal* meta = new WrongAnimal();
	// 	const WrongAnimal* i = new WrongCat();
	// 	std::cout << meta->getType() << std::endl;
	// 	std::cout << i->getType() << std::endl;
	// 	i->makeSound(); //will output the WrongCat sound!
	// 	meta->makeSound(); //Will output the WrongAnimal sound!
	// 	delete meta;
	// 	delete i;
	// }

	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:16:29 by acarlott          #+#    #+#             */
/*   Updated: 2023/11/23 17:24:40 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/WrongCat.hpp"

int main() {
	{
		int	x = 10;
		int	i = 0;
		
		std::cout << "CREATING ANIMALS TAB:" << std::endl;
		Animal const	*tab[x];
		for (; i < x; i++) {
			if (i < x / 2)
				tab[i] = new Dog();
			else
				tab[i] = new Cat();
		}
		std::cout << std::endl << "TEST: FIRST HALF TAB IS DOG OTHER HALF IS CAT" << std::endl;
		for (i = 0; i < x; i++) {
			tab[i]->makeSound();
		}
		std::cout << std::endl << "DELETING ANIMALS TAB:" << std::endl;
		for (i = 0; i < x; i++)
			delete tab[i];
	}
	{
		std::cout << std::endl << "TESTING DEEP COPY:" << std::endl;
		Animal	*dog = new Dog();
		Animal	*cat = new Cat();
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
		Animal	*twinDog = new Dog(*dog);
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
// 	const Animal* meta = new Animal();
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();
// 	std::cout << meta->getType() << std::endl;
// 	std::cout << j->getType() << std::endl;
// 	std::cout << i->getType() << std::endl;
// 	i->makeSound(); //will output the Cat sound!
// 	j->makeSound(); //will output the Dog sound!
// 	meta->makeSound(); //Will output the Animal sound!
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:16:29 by acarlott          #+#    #+#             */
/*   Updated: 2023/11/23 18:00:59 by acarlott         ###   ########lyon.fr   */
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
// {
// 	const Animal* meta = new Animal();
// 	const Animal* dog = new Dog();
// 	const Animal* cat = new Cat();
// 	std::cout << meta->getType() << std::endl;
// 	std::cout << dog->getType() << std::endl;
// 	std::cout << cat->getType() << std::endl;
// 	cat->makeSound(); //will output the Cat sound!
// 	dog->makeSound(); //will output the Dog sound!
// 	meta->makeSound(); //Will output the Animal sound!
// 	delete meta;
// 	delete dog;
// 	delete cat;
// }
// {
// 	const WrongAnimal* Wrong_animals = new WrongAnimal();
// 	const WrongAnimal* Wrong_cat_f = new WrongCat();
// 	const WrongCat* Wrong_cat_k = new WrongCat();
// 	std::cout << "Animal type : " << Wrong_animals->getType() << std::endl;
// 	std::cout << "Animal type : " << Wrong_cat_f->getType() << std::endl;
// 	std::cout << "Animal type : " << Wrong_cat_k->getType() << std::endl;
// 	Wrong_animals->makeSound(); //Will output the WrongAnimal sound!
// 	Wrong_cat_f->makeSound(); //will output the WrongAnimal sound!
// 	Wrong_cat_k->makeSound(); //will output the WrongCat sound!
// 	delete Wrong_animals;
// 	delete Wrong_cat_f;
// 	delete Wrong_cat_k;
// }

return 0;
}

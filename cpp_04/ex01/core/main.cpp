/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:16:29 by acarlott          #+#    #+#             */
/*   Updated: 2023/11/22 17:23:13 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main() {
	{
		int	x = 10;
		int	i = 0;
		
		std::cout << "CREATING ANIMALS TAB:" << std::endl;
		Animal	*tab[x];
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
		std::cout << std::endl << "TESTING DEEP COPY:" << std::endl;
		std::cout << std::endl << "DELETING ANIMALS TAB:" << std::endl;
		for (i = 0; i < x; i++)
			delete tab[i];
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

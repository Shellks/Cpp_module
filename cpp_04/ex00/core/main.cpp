/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:16:29 by acarlott          #+#    #+#             */
/*   Updated: 2023/12/13 11:36:31 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/WrongCat.hpp"

int main() {
{
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	std::cout << meta->getType() << std::endl;
	std::cout << dog->getType() << std::endl;
	std::cout << cat->getType() << std::endl;
	cat->makeSound();
	dog->makeSound();
	meta->makeSound();
	delete meta;
	delete dog;
	delete cat;
}
{
	const WrongAnimal* Wrong_animals = new WrongAnimal();
	const WrongAnimal* Wrong_cat_f = new WrongCat();
	const WrongCat* Wrong_cat_k = new WrongCat();
	std::cout << "Animal type : " << Wrong_animals->getType() << std::endl;
	std::cout << "Animal type : " << Wrong_cat_f->getType() << std::endl;
	std::cout << "Animal type : " << Wrong_cat_k->getType() << std::endl;
	Wrong_animals->makeSound();
	Wrong_cat_f->makeSound();
	Wrong_cat_k->makeSound();
	delete Wrong_animals;
	delete Wrong_cat_f;
	delete Wrong_cat_k;
}

return 0;
}

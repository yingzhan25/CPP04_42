/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yingzhan <yingzhan@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 14:31:50 by yingzhan          #+#    #+#             */
/*   Updated: 2025/11/24 15:40:55 by yingzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "\033[32m" << "====================Animal array===================" << "\033[0m" << std::endl;

	const int	N = 2;
	Animal*	animals[N];
	std::cout << "\033[33m" << "=====================Create Dogs===================" << "\033[0m" << std::endl;
	for (int i = 0; i < (N / 2); i++)
		animals[i] = new Dog();
	std::cout << "\033[33m" << "=====================Create Cats===================" << "\033[0m" << std::endl;
	for (int i = (N / 2); i < N ; i++)
		animals[i] = new Cat();
	std::cout << "\033[33m" << "=====================Make sounds===================" << "\033[0m" << std::endl;
	for (int i = 0; i < N; i++)
	{
		std::cout << animals[i]->getType() << " ";
		animals[i]->makeSound();
	}
	std::cout << "\033[33m" << "===================Delete animals==================" << "\033[0m" << std::endl;
	for (int i = 0; i < N; i++)
		delete animals[i];

	std::cout << "\033[32m" << "============Deep copy: copy constructor============" << "\033[0m" << std::endl;

	Dog*	dog = new Dog();
	dog->setIdea(0, "WALK");
	Dog*	copyDog = new Dog(*dog);
	std::cout << "Original dog: " << dog->getIdea(0) << std::endl;
	std::cout << "Copy dog: " << copyDog->getIdea(0) << std::endl;

	std::cout << "\033[33m" << "====================Change ideas===================" << "\033[0m" << std::endl;
	copyDog->setIdea(0, "FOOD");
	std::cout << "Original dog: " << dog->getIdea(0) << std::endl;
	std::cout << "Copy dog: " << copyDog->getIdea(0) << std::endl;

	std::cout << "\033[33m" << "====================Delete dogs====================" << "\033[0m" << std::endl;
	delete dog;
	delete copyDog;

	std::cout << "\033[32m" << "==========Deep copy: assignment operator===========" << "\033[0m" << std::endl;

	Cat	cat = Cat();
	cat.setIdea(0, "SLEEP");
	Cat	copyCat = Cat();
	copyCat = cat;
	std::cout << "Original cat: " << cat.getIdea(0) << std::endl;
	std::cout << "Copy cat: " << copyCat.getIdea(0) << std::endl;

	std::cout << "\033[33m" << "====================Change ideas===================" << "\033[0m" << std::endl;
	copyCat.setIdea(0, "PLAY");
	std::cout << "Original cat: " << cat.getIdea(0) << std::endl;
	std::cout << "Copy cat: " << copyCat.getIdea(0) << std::endl;

	std::cout << "\033[32m" << "====================Polymorphism===================" << "\033[0m" << std::endl;

	const Animal*	j = new Dog();
	const Animal*	i = new Cat();

	std::cout << "\033[33m" << "===================Delete animals==================" << "\033[0m" << std::endl;
	delete i;
	delete j;

	std::cout << "\033[32m" << "====================Destructor=====================" << "\033[0m" << std::endl;

	return (0);
}
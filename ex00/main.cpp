/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yingzhan <yingzhan@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 14:31:50 by yingzhan          #+#    #+#             */
/*   Updated: 2025/11/23 16:26:41 by yingzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "\033[32m" << "=====================Animal========================" << "\033[0m" << std::endl;
	Animal	a;
	Animal	b(a);
	Animal	c;
	c = a;
	std::cout << a.getType() << " " << std::endl;
	a.makeSound();

	std::cout << "\033[32m" << "=======================Cat=========================" << "\033[0m" << std::endl;
	Cat	d;
	Cat	e(d);
	Cat	f;
	f = d;
	std::cout << d.getType() << " " << std::endl;
	d.makeSound();

	std::cout << "\033[32m" << "=======================Dog=========================" << "\033[0m" << std::endl;
	Dog	g;
	Dog	h(g);
	Dog	k;
	k = g;
	std::cout << g.getType() << " " << std::endl;
	g.makeSound();

	std::cout << "\033[32m" << "====================Polymorphism====================" << "\033[0m" << std::endl;
	const Animal*	meta = new Animal();
	const Animal*	j = new Dog();
	const Animal*	i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete i;
	delete j;

	std::cout << "\033[32m" << "====================Wrong Animals====================" << "\033[0m" << std::endl;
	const WrongAnimal*	wrongMeta = new WrongAnimal();
	const WrongAnimal*	wrongCat = new WrongCat();

	std::cout << wrongCat->getType() << " " << std::endl;
	wrongMeta->makeSound();
	wrongCat->makeSound();

	delete wrongMeta;
	delete wrongCat;

	std::cout << "\033[32m" << "====================Destructor=======================" << "\033[0m" << std::endl;

	return (0);
}
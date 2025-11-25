/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yingzhan <yingzhan@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:57:03 by yingzhan          #+#    #+#             */
/*   Updated: 2025/11/25 15:01:10 by yingzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include <iostream>

void	testMandatory(void)
{
	std::cout << "\033[32m" << "====================testMandatory===================" << "\033[0m" << std::endl;

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

void	testUnequipped(void)
{
	std::cout << "\033[32m" << "====================testUnequipped===================" << "\033[0m" << std::endl;

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* ice = src->createMateria("ice");
	me->equip(ice);
	AMateria* cure = src->createMateria("cure");
	me->equip(cure);

	ICharacter* bob = new Character("bob");
	std::cout << "\033[33m" << "===================Before unequip=================" << "\033[0m" << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);

	//Record memory addreass of unequipped to avoid memory leak
	AMateria* floor[10];
	int	num = 0;
	floor[num++] = ice;
	me->unquip(0);

	std::cout << "\033[33m" << "===================After unequip==================" << "\033[0m" << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);

	for (int i = 0; i < num; i++)
		delete floor[i];

	delete bob;
	delete me;
	delete src;
}

void	testInventory(void)
{
	std::cout << "\033[32m" << "====================testInventory===================" << "\033[0m" << std::endl;

	ICharacter* me = new Character("me");
	ICharacter* target = new Character("target");

	me->equip(new Ice());
	me->equip(new Cure());
	me->equip(new Ice());
	me->equip(new Cure());

	AMateria* extra = new Ice();
	me->equip(extra);

	me->use(0, *target);
	me->use(1, *target);
	me->use(2, *target);
	me->use(3, *target);

	//Delete because not successfully equipped
	delete extra;
	delete me;
	delete target;
}

void	testMateriaSource(void)
{
	std::cout << "\033[32m" << "==================testMateriaSource=================" << "\033[0m" << std::endl;

	MateriaSource	source;

	source.learnMateria(new Ice());
	source.learnMateria(new Cure());
	source.learnMateria(new Ice());
	source.learnMateria(new Cure());
	//Will be deleted inside learn function when more than 4 templates
	source.learnMateria(new Ice());

	AMateria* ice = source.createMateria("ice");
	AMateria* cure = source.createMateria("cure");
	AMateria* unknown = source.createMateria("fire");

	if (ice)
		std::cout << ice->getType() << " is created" << std::endl;
	if (cure)
		std::cout << cure->getType() << " is created" << std::endl;
	if (!unknown)
		std::cout << "Return NULL" << std::endl;

	delete ice;
	delete cure;
}

void	testDeepCopy(void)
{
	std::cout << "\033[32m" << "====================testDeepCopy===================" << "\033[0m" << std::endl;

	Character*	a = new Character("a");
	ICharacter*	enemy = new Character("enemy");
	AMateria* ice = new Ice();
	a->equip(ice);
	Character*	b = new Character(*a);
	Character*	c = new Character("c");
	*c = *a;

	std::cout << "\033[33m" << "===================Before unequip=================" << "\033[0m" << std::endl;
	std::cout << "a: ";
	a->use(0, *enemy);
	std::cout << "b: ";
	b->use(0, *enemy);
	std::cout << "c: ";
	c->use(0, *enemy);

	a->unquip(0);
	std::cout << "\033[33m" << "===================After unequip==================" << "\033[0m" << std::endl;
	std::cout << "a: ";
	a->use(0, *enemy);
	std::cout << "b: ";
	b->use(0, *enemy);
	std::cout << "c: ";
	c->use(0, *enemy);

	//delete unequipped
	delete ice;
	delete a;
	delete b;
	delete c;
	delete enemy;
}

int	main(void)
{
	testMandatory();
	testUnequipped();
	testInventory();
	testMateriaSource();
	testDeepCopy();

	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yingzhan <yingzhan@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 22:55:06 by yingzhan          #+#    #+#             */
/*   Updated: 2025/11/25 10:42:39 by yingzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(const std::string name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		slots[i] = NULL;
}

Character::Character(const Character& other) : _name(other._name)
{
	for (int i = 0; i < 4; i++)
	{
		if (other.slots[i] != NULL)
			slots[i] = other.slots[i]->clone();
		else
			slots[i] = NULL;
	}
}

Character&	Character::operator=(const Character& other)
{
	if (this != &other)
	{
		_name = other._name;
		for (int i = 0; i < 4; i++)
		{
			if (slots[i] != NULL)
				delete slots[i];
			if (other.slots[i] != NULL)
				slots[i] = other.slots[i]->clone();
			else
				slots[i] = NULL;
		}
	}
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (slots[i] != NULL)
			delete slots[i];
	}
}

std::string const&	Character::getName() const
{
	return (_name);
}

void	Character::equip(AMateria* m)
{
	if (m == NULL)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (slots[i] == NULL)
		{
			slots[i] = m;
			return ;
		}
	}
}

void	Character::unquip(int idx)
{
	if (idx < 0 || idx > 3)
		return ;
	if (slots[idx] != NULL)
		slots[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
		return ;
	if (slots[idx] != NULL)
		slots[idx]->use(target);
}
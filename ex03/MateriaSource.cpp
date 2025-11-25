/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yingzhan <yingzhan@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:27:41 by yingzhan          #+#    #+#             */
/*   Updated: 2025/11/25 14:20:01 by yingzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		templates[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	for (int i = 0; i < 4; i++)
	{
		if (other.templates[i] != NULL)
			templates[i] = other.templates[i]->clone();
		templates[i] = NULL;
	}
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (templates[i] != NULL)
				delete templates[i];
			if (other.templates[i] != NULL)
				templates[i] = other.templates[i]->clone();
			templates[i] = NULL;
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (templates[i] != NULL)
			delete templates[i];
	}
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (m == NULL)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (templates[i] == NULL)
		{
			templates[i] = m->clone();
			delete m;
 			return ;
		}
	}
	delete m;
}

AMateria*	MateriaSource::createMateria(std::string const& type)
{
	(void)type;
	for (int i = 0; i < 4; i++)
	{
		if (templates[i] != NULL)
		{
			if (templates[i]->getType() == type)
				return (templates[i]->clone());
		}
	}
	return (NULL);
}
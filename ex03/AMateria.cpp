/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yingzhan <yingzhan@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 20:34:39 by yingzhan          #+#    #+#             */
/*   Updated: 2025/11/24 21:07:47 by yingzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("default") {}

AMateria::AMateria(std::string const& type) : _type(type) {}

AMateria::AMateria(const AMateria& other) : _type(other._type) {}

AMateria&	AMateria::operator=(const AMateria& other)
{
	if (this != &other)
		_type = other._type;
	return (*this);
}

AMateria::~AMateria() {}

std::string const& AMateria::getType()const
{
	return (_type);
}

void	AMateria::use(ICharacter& target)
{
	(void)target;
}
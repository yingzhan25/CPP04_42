/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yingzhan <yingzhan@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 18:22:06 by yingzhan          #+#    #+#             */
/*   Updated: 2025/11/25 11:10:39 by yingzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string	_type;
		AMateria(const AMateria& other);
	public:
		AMateria();
		AMateria(std::string const& type);
		AMateria& operator=(const AMateria& other);
		virtual ~AMateria();

		std::string const& getType()const;
		virtual AMateria*	clone()const = 0;
		virtual void	use(ICharacter& target);
};

#endif
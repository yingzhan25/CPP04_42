/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yingzhan <yingzhan@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 22:05:33 by yingzhan          #+#    #+#             */
/*   Updated: 2025/11/25 10:03:21 by yingzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include <string>

class Character : public ICharacter
{
	private:
		std::string	_name;
		AMateria*	slots[4];
		Character();
	public:
		Character(const std::string name);
		Character(const Character& other);
		Character&	operator=(const Character& other);
		virtual ~Character();

		virtual std::string const&	getName() const;
		virtual void	equip(AMateria* m);
		virtual void	unquip(int idx);
		virtual void	use(int idx, ICharacter& target);
};

#endif
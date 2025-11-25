/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yingzhan <yingzhan@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 10:47:41 by yingzhan          #+#    #+#             */
/*   Updated: 2025/11/23 14:51:35 by yingzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
	protected:
		std::string	type;
	public:
		Animal();
		Animal(const Animal& other);
		Animal&	operator=(const Animal& other);
		virtual ~Animal();

		virtual void	makeSound(void)const;
		const std::string&	getType()const;
};

#endif
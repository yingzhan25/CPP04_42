/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yingzhan <yingzhan@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 10:47:41 by yingzhan          #+#    #+#             */
/*   Updated: 2025/11/24 16:03:39 by yingzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>

class AAnimal
{
	protected:
		std::string	type;
	public:
		AAnimal();
		AAnimal(const AAnimal& other);
		AAnimal&	operator=(const AAnimal& other);
		virtual ~AAnimal();

		virtual void	makeSound(void)const = 0;
		const std::string&	getType()const;
};

#endif
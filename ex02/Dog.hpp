/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yingzhan <yingzhan@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 14:24:28 by yingzhan          #+#    #+#             */
/*   Updated: 2025/11/24 16:05:55 by yingzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Brain.hpp"
#include "AAnimal.hpp"

class Dog: public AAnimal
{
	private:
		Brain*	brain;
	public:
		Dog();
		Dog(const Dog& other);
		Dog&	operator=(const Dog& other);
		virtual ~Dog();

		virtual void	makeSound(void)const;
		void	setIdea(const int index, const std::string& idea);
		const std::string	getIdea(const int index)const;
};

#endif
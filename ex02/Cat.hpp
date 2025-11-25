/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yingzhan <yingzhan@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 14:04:48 by yingzhan          #+#    #+#             */
/*   Updated: 2025/11/24 16:05:25 by yingzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Brain.hpp"
#include "AAnimal.hpp"

class Cat: public AAnimal
{
	private:
		Brain*	brain;
	public:
		Cat();
		Cat(const Cat& other);
		Cat&	operator=(const Cat& other);
		virtual ~Cat();

		virtual void	makeSound(void)const;
		void	setIdea(const int index, const std::string& idea);
		const std::string	getIdea(const int index)const;
};

#endif
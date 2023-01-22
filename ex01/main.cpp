/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 22:17:21 by ziloughm          #+#    #+#             */
/*   Updated: 2023/01/22 23:32:32 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

int main(void)
{
	PhoneBook	p;

	while (1)
	{
		p.printHearder();
		p.inputCmd();
		std::cout << std::endl;
		switch (p.typeCmd())
		{
			case 0:
				return (0);
				break;
			case 1:
				p.addContact();
				break;
			case 2:
				p.searchContact();
				break;
			default:
				std::cout << RED << "Invalid command !!!!" << WHI << std::endl;
				break;
		}
	}
	return (0);
}

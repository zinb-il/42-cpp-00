/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 11:49:24 by ziloughm          #+#    #+#             */
/*   Updated: 2023/01/23 18:24:01 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int ac, char **av)
{
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        for (int i = 1 ; i < ac ; i++)
            for (size_t j = 0; j < static_cast<std::string>(av[i]).length(); j++)
                std::cout << static_cast<char>(std::toupper(av[i][j]));
        std::cout << "\n";
    }
    return (0);
    
}
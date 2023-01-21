/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 11:49:24 by ziloughm          #+#    #+#             */
/*   Updated: 2023/01/21 22:37:02 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        for (int i = 1 ; i < ac ; i++)
            for (size_t j = 0; j < strlen(av[i]); j++)
                std::cout << static_cast<char>(std::toupper(av[i][j]));
        std::cout << "\n";
    }
    return (0);
    
}
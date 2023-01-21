/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:58:02 by ziloughm          #+#    #+#             */
/*   Updated: 2023/01/21 21:18:14 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#   ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

class   PhoneBook
{
    public:
        PhoneBook();
        ~PhoneBook();
        void    addContact();
        void    searchContact();
    private:
        int     _index;    /*Contact _contacts[8];*/
};

#   endif
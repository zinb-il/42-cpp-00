/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:58:02 by ziloughm          #+#    #+#             */
/*   Updated: 2023/01/23 18:21:29 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#   ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#define RED     "\033[0;31m"
#define YELLOW  "\033[1;33m"
#define GREEN   "\033[0;32m"
#define BLUE    "\033[0;34m"
#define WHI     "\033[0;0m"
#define SIZE    8

class   PhoneBook
{
    public:
        PhoneBook();
        ~PhoneBook();
        int         getIndex(void) const;
        void        setIndex(int index);
        std::string getCmd(void) const;
        std::string getInput(std::string field) const;
        std::string displayInput(std::string field) const;
        void        setCmd(std::string cmd);
        void        inputCmd(void);
        int         typeCmd(void) const;
        void        printHearder(void) const;
        void        addContact(void);
        void        searchContact(void);
        void        printContacts(void) const;
        void        printContact(int index) const;
    private:
        std::string     _cmd;
        Contact         _contacts[SIZE];
        int             _index;
        
};

#   endif
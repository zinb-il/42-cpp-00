/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:58:02 by ziloughm          #+#    #+#             */
/*   Updated: 2023/01/25 17:00:23 by ziloughm         ###   ########.fr       */
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
        void        setIndex(int index);
        int         getIndex(void) const;
        int         get_index_nb(std::string in);
        int         get_phone_nb(std::string in);
        std::string getCmd(void) const;
        std::string getInput(std::string field) const;
        std::string displayInput(std::string field) const;
        void        setCmd(std::string cmd);
        void        inputCmd(void);
        int         typeCmd(void) const;
        void        printHearder(void) const;
        void        addContact(void);
        void        searchContact(void);
        void        printContactHead(void) const;
        bool        printContacts(void) const;
        void        printContact(int index) const;
        void        printContactLine(int index) const;
    private:
        std::string     _cmd;
        Contact         _contacts[SIZE];
        int             _index;
        
};

#   endif
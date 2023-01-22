/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:33:05 by ziloughm          #+#    #+#             */
/*   Updated: 2023/01/22 23:53:12 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

PhoneBook::PhoneBook()
{
    this->_index = 0;
    std::cout << "PhoneBook created" << std::endl;
}

PhoneBook::~PhoneBook()
{
    std::cout <<  "PhoneBook destroyed" << std::endl;
}

std::string PhoneBook::getCmd(void) const
{
    return (this->_cmd);
}

void    PhoneBook::setCmd(std::string cmd)
{
    this->_cmd = cmd;
}

int PhoneBook::getIndex(void) const
{
    return (this->_index);
}

void    PhoneBook::setIndex(int index)
{
    this->_index = index;
}

void PhoneBook::printHearder(void) const
{
    std::cout << "\n Choose a command \t"
    << RED << "EXIT" << WHI << " | "
    << YELLOW << "ADD" << WHI << " | "
    << BLUE << "SEARCH" << WHI << "\n"
    << ">>";
}

void    PhoneBook::inputCmd(void)
{
    std::string cmd;
    
    if (!(std::getline(std::cin, cmd)) || std::cin.eof())
        exit(1);
    this->setCmd(cmd);
}

int     PhoneBook::typeCmd(void) const
{
    if (this->_cmd == "EXIT")
        return (0);
    else if (this->_cmd == "ADD")
        return (1);
    else if (this->_cmd == "SEARCH")
        return (2);
    else
        return (3);
}
std::string PhoneBook::getInput(std::string field) const
{
    std::string input;
    
    std::cout << "Plese enter the " << field << std::endl;
    if(!(std::getline(std::cin >> std::ws, input)) || std::cin.eof())
        exit(1);
    return (input);
}

std::string PhoneBook::displayInput(std::string field) const
{
    std::string input;
    
    if (field.length() > 10)
    {
        input = field.substr(0, 9);
        input += ".";
    }
    else
        input = field;
    return (input);
}

void PhoneBook::addContact(void)
{
    std::cout << YELLOW << "Adding a contact to your PhoneBook" << WHI << std::endl;
    this->_contacts[this->_index].setPrenom(this->getInput("FirstName"));
    this->_contacts[this->_index].setNom(this->getInput("LastName"));
    this->_contacts[this->_index].setLogin(this->getInput("NickName"));
    this->_contacts[this->_index].setPhone(this->getInput("Phone"));
    this->_contacts[this->_index].setPseudo(this->getInput("Darkest Secret"));
    this->setIndex((++this->_index) % SIZE);
    std::cout << GREEN << "Your new contact is successfully added" << WHI << std::endl;
}

void    PhoneBook::printContacts(void) const
{
    std::cout << std::setw(10)  << "Index" << " | " << 
    std::setw(10) << "First Name" << " | " << 
    std::setw(10) << "Last Name" << " | " <<
    std::setw(10) << "Nickname" << " | "  << std::endl;
    for (int i = 0 ; i < SIZE ; i++)
    {
        std::cout << "---------------------------------------------------" << 
        std::endl << std::setw(10) << i << " | " << 
        std::setw(10) << this->displayInput(this->_contacts[i].getPrenom()) << " | " << 
        std::setw(10) << this->displayInput(this->_contacts[i].getNom()) << " | " <<
        std::setw(10) << this->displayInput(this->_contacts[i].getLogin()) << " | " << std::endl;
    }
}

void PhoneBook::searchContact(void)
{
    std::cout << BLUE << "Searching for a contact on your PhoneBook" << WHI << std::endl;
    this->printContacts();
    
}
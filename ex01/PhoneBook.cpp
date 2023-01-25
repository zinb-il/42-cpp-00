/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:33:05 by ziloughm          #+#    #+#             */
/*   Updated: 2023/01/25 17:22:56 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

PhoneBook::PhoneBook()
{
    this->_index = 0;
}

PhoneBook::~PhoneBook()
{
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
    std::cout << std::endl << "Choose a command \t"
    << RED << "EXIT" << WHI << " | "
    << YELLOW << "ADD" << WHI << " | "
    << BLUE << "SEARCH" << WHI << std::endl
    << ">>";
}

void    PhoneBook::inputCmd(void)
{
    std::string cmd;
    
    if (!(std::getline(std::cin, cmd)) || std::cin.eof())
        exit(1);
    this->setCmd(cmd);
    std::cout << std::endl;
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
    
    std::cout << "Please enter the " << field << std::endl;
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
    int phone;
    
    std::cout << YELLOW << "Adding a contact to your PhoneBook" << WHI << std::endl;
    this->_contacts[this->_index].setPrenom(this->getInput("FirstName"));
    this->_contacts[this->_index].setNom(this->getInput("LastName"));
    this->_contacts[this->_index].setLogin(this->getInput("NickName"));
    phone = PhoneBook::get_phone_nb(this->getInput("Phone"));
    while (phone == 1)
         phone = PhoneBook::get_phone_nb(this->getInput("Phone"));
    this->_contacts[this->_index].setPseudo(this->getInput("Darkest Secret"));
    this->setIndex((++this->_index) % SIZE);
    std::cout << GREEN << "Your new contact is successfully added" << WHI << std::endl;
}

void    PhoneBook::printContactHead(void) const
{
    std::cout << std::setw(10)  << "Index" << "|" << 
    std::setw(10) << "First Name" << "|" << 
    std::setw(10) << "Last Name" << "|" <<
    std::setw(10) << "Nickname" << "|"  << std::endl;
    std::cout << "--------------------------------------------" << 
    std::endl ;
}
void    PhoneBook::printContactLine(int index) const
{
    if (!this->_contacts[index].getPrenom().size())
    {
        std::cout << RED << "This contact doesn't exit" << WHI << std::endl;
        return ;
    }
    std::cout << std::setw(10) << index + 1 << "|" << 
    std::setw(10) << this->displayInput(this->_contacts[index].getPrenom()) << "|" << 
    std::setw(10) << this->displayInput(this->_contacts[index].getNom()) << "|" <<
    std::setw(10) << this->displayInput(this->_contacts[index].getLogin()) << "|" << std::endl;
    std::cout << "--------------------------------------------" << 
    std::endl ;
}

bool    PhoneBook::printContacts(void) const
{
    if (!this->_contacts[0].getPrenom().size())
    {
        std::cout << RED << "Your PhonBook is empry !" << WHI << std::endl;
        return (false);
    }
    PhoneBook::printContactHead();
    for (int i = 0 ; i < SIZE ; i++)
    {
        if (!this->_contacts[i].getPrenom().size())
            continue ;
        PhoneBook::printContactLine(i);
    }
    return (true);
}

void    PhoneBook::printContact(int index) const
{
    if (!this->_contacts[index].getPrenom().size())
    {
        std::cout << RED << "This contact doesn't exit" << WHI << std::endl;
        return ;
    }
    PhoneBook::printContactHead();
    PhoneBook::printContactLine(index);
}

int PhoneBook::get_index_nb(std::string in)
{
    int index;
    
    try
    {
       index = std::stoi(in);
    }
    catch (std::exception &e)
    {
        std::cout << RED << "Please enter a valid index" << WHI << std::endl;
        return (-1);
    }
    if (index < 1 || index > SIZE)
    {
       std::cout << RED << "Please enter a valid index" << WHI << std::endl;
        return (-1);
    }
    return (index - 1);
}

int PhoneBook::get_phone_nb(std::string in)
{
    int phone;
    
    try
    {
       phone = std::stoi(in);
    }
    catch (std::exception &e)
    {
        std::cout << RED << "Please enter a valid phone number" << WHI << std::endl;
        return (1);
    }
    if (phone < 0)
    {
       std::cout << RED << "Please enter a valid phone number" << WHI << std::endl;
        return (1);
    }
    return (0);
}

void PhoneBook::searchContact(void)
{
    int index;
    
    if (!(this->printContacts()))
        return ;
    std::cout << BLUE << std::endl << "Searching for a contact on your PhoneBook" << WHI << std::endl << std::endl;
    index = PhoneBook::get_index_nb(this->getInput("Index"));
    while (index < 0)
        index = PhoneBook::get_index_nb(this->getInput("Index"));
    this->printContact(index);
}
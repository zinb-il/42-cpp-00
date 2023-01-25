/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 21:00:49 by ziloughm          #+#    #+#             */
/*   Updated: 2023/01/25 15:43:00 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

std::string Contact::getNom(void) const
{
    return (this->_nom);
}

std::string Contact::getPrenom(void) const
{
    return (this->_prenom);
}

std::string Contact::getPseudo(void) const
{
    return (this->_pseudo);
}

std::string Contact::getLogin(void) const
{
    return (this->_login);
}

std::string Contact::getPhone(void) const
{
    return (this->_phone);
}

void Contact::setNom(std::string nom)
{
    this->_nom = nom;
}

void Contact::setPrenom(std::string prenom)
{
    this->_prenom = prenom;
}

void Contact::setPseudo(std::string pseudo)
{
    this->_pseudo = pseudo;
}

void Contact::setLogin(std::string login)
{
    this->_login = login;
}

void Contact::setPhone(std::string phone)
{
    this->_phone = phone;
}
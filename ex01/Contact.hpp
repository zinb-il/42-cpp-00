/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 21:00:54 by ziloughm          #+#    #+#             */
/*   Updated: 2023/01/25 16:59:14 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#   ifndef CONTACT_HPP
# define CONTACT_HPP

class Contact
{
    public:
        Contact(void);
        ~Contact(void);
        std::string getNom(void)const;
        std::string getPrenom(void)const;
        std::string getPseudo(void)const;
        std::string getLogin(void)const;
        std::string getPhone(void)const;
        void setNom(std::string nom);
        void setPrenom(std::string prenom);
        void setPseudo(std::string pseudo);
        void setLogin(std::string login);
        void setPhone(std::string phone);
    private:
        std::string _nom;
        std::string _prenom;
        std::string _pseudo;
        std::string _login;
        std::string _phone;
};

#   endif
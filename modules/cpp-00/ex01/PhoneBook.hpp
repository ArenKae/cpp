/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:50:59 by acosi             #+#    #+#             */
/*   Updated: 2024/06/17 14:50:59 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"
#include <iostream>

class PhoneBook
{
    private:
        Contact MyContacts[8];
    public:
        PhoneBook(void);
        ~PhoneBook(void);
        void ft_add(int i);
        void ft_search(void);
};

#endif
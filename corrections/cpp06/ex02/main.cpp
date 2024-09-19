/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtassel <dtassel@42.nice.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 09:58:17 by dtassel           #+#    #+#             */
/*   Updated: 2024/01/19 11:20:17 by dtassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <stdlib.h>
#include <ctime>

void    identify(Base &p)
{
    try
    {
        dynamic_cast<A &>(p);
        std::cout << "type reference : A" << std::endl;
    }
    catch(const std::exception& e){}
    try
    {
        dynamic_cast<B &>(p);
        std::cout << "type reference : B" << std::endl;
    }
    catch(const std::exception& e){}
    try
    {
        dynamic_cast<C &>(p);
        std::cout << "type reference : C" << std::endl;
    }
    catch(const std::exception& e){}
}

void    identify(Base *p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "type pointeur : A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "type pointeur : B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "type pointeur : C" << std::endl;
}

Base *generate(void)
{
    switch (rand() % 3)
    {
    case 0:
    {
        A *a = new A;
        return a;
    }
    case 1:
    {
        B *b = new B;
        return b;
    }
    case 2:
    {
        C *c = new C;
        return c;
    }
    }
    return NULL;
}

int main(void)
{
    srand(time(NULL));
    std::cout << "----------------------" << std::endl;
    {
        Base *baseptr = generate();
        identify(baseptr);
        identify(*baseptr);
        delete baseptr;
    }
    std::cout << "----------------------" << std::endl;
    {
        Base *baseptr = generate();
        identify(baseptr);
        identify(*baseptr);
        delete baseptr;
    }
    std::cout << "----------------------" << std::endl;
    {
        Base *baseptr = generate();
        identify(baseptr);
        identify(*baseptr);
        delete baseptr;
    }
    std::cout << "----------------------" << std::endl;
    return 0;
}
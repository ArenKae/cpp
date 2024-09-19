/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtassel <dtassel@42.nice.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:34:51 by dtassel           #+#    #+#             */
/*   Updated: 2024/01/18 11:51:57 by dtassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
    Data *data = new Data;
    data->name = "David";
    data->age = 32;

    uintptr_t serialized = Serializer::serialize(data);
    std::cout << serialized << std::endl;

    Data *deserData = Serializer::deserialize(serialized);
    std::cout << "name : " << deserData->name << std::endl;
    std::cout << "age : " << deserData->age << std::endl;

    std::cout << "pointeur d'origine : " << data << std::endl;
    std::cout << "pointeur deserialisation : " << deserData << std::endl;
    delete data;
    return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:51:08 by acosi             #+#    #+#             */
/*   Updated: 2024/06/30 05:01:24 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
#define UTILS_H

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#define OPEN 2
#define CREATE 3
#define TOO_MANY_ARGS 4
#define TOO_FEW_ARGS 5

int	print_error(const char* filename, int flag);

#endif
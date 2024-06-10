#ifndef UTILS_H
#define UTILS_H

#include <iostream>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

#define NEWLINE 0
#define NONEWLINE 1

void print_prompt(void);
void print_error(const std::string& message, int flag);
void error_empty(void);

#endif
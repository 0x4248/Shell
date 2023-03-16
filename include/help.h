/* Shell (help.h)
 * A simple shell made in C++
 * Github: https://www.github.com/awesomelewis2007/shell
 *
 * Help command header file
*/

#include <iostream>

/**
 * Prints the help message
 * @returns: void
*/
void help(){
    std::cout << "awesomelewis2007's shell help" << std::endl;
    std::cout << "help - show this help message" << std::endl;
    std::cout << "exit - exit the shell" << std::endl;
}
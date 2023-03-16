/* Shell (printsh.h)
 * A simple shell made in C++
 * Github: https://www.github.com/awesomelewis2007/shell
 *
 * Shell verbose handler header file
*/
#include <iostream>
#include <string>

/**
 * printsh - print a message to the shell
 * @message: std::string
 * @returns: void
*/
void printsh(std::string message){
    std::cout << message << std::endl;
}

/**
 * pr_error - print an error message to the shell
 * @message: std::string
 * @returns: void
*/
void pr_error(std::string message){
    std::cerr << message << std::endl;
}

/**
 * pr_warning - print a warning message to the shell
 * @message: std::string
 * @returns: void
*/
void pr_warning(std::string message){
    std::cout << message << std::endl;
}
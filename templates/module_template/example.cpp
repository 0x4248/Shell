/* Shell (example.cpp)
 * A simple shell made in C++
 * Github: https://www.github.com/awesomelewis2007/shell
 * Licence: GPL-3.0
 * By: Lewis Evans
 *
 * Shell example module source file
*/


#include <iostream>
#include <string>

#include "printsh.h"
#include "config/config.h"


/**
 * example_function - Prints hello [arg] using the printsh function
*/
void example_function(std::string args){
    printsh("hello "+args);
}
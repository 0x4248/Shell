/* Shell (example.cpp)
 * A simple shell made in C++
 * Github: https://www.github.com/awesomelewis2007/shell
 * Licence: GPL-3.0
 * By: Lewis Evans
 *
 * Shell example command source file
*/


#include <iostream>
#include <string>

#include "printsh.h"
#include "config/config.h"


/**
 * example_command - Prints hello [arg] using the printsh function
*/
int example_command(std::string args){
    printsh("hello "+args);
}

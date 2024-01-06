/* Shell (example.cpp)
 * A simple shell made in C++
 * Github: https://www.github.com/lewisevans2007/shell
 * Licence: GNU General Public License v3.0
 * By: Lewis Evans
 *
 * Shell example command source file
 */

#include <iostream>
#include <string>

#include "config/config.h"
#include "printsh.h"

/**
 * example_command - Prints hello [arg] using the printsh function
 */
int example_command(std::string args) { printsh("hello " + args); }

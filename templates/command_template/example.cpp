/* Shell (example.cpp)
 * A simple shell made in C++
 * Github: https://www.github.com/0x4248/shell
 * Licence: GNU General Public License v3.0
 * By: 0x4248
 *
 * Shell example command source file
 */

#include <iostream>
#include <string>

#include "config/config.h"
#include "printsh.h"

/**
 * example_command - Prints hello [arg] using the printsh
 * function and returns 0
 */
int example_command(std::string args) {
    printsh("hello " + args);
    return 0;
}

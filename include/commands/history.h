/* Shell (history.h)
 * A simple shell made in C++
 * Github: https://www.github.com/awesomelewis2007/shell
 * Licence: GPL-3.0
 * By: Lewis Evans
 *
 * Shell history command header file
 */

#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

/**
 * Prints the shell history
 * @returns: void
 */
int history_command(std::string args);
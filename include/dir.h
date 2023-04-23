/* Shell (dir.cpp)
 * A simple shell made in C++
 * Github: https://www.github.com/awesomelewis2007/shell
 * Licence: GPL-3.0
 * By: Lewis Evans
 *
 * directory helper functions
*/

#include <string>

/**
 * Gets the current directory
 * @returns: std::string
 */
std::string get_current_directory();

/**
 * Formats the current directory string to make
 * the top most folder coloured cyan and the rest
 * of the directory coloured blue.
 * @param directory: std::string
 * @returns: std::string
 */
std::string format_current_directory(std::string directory);

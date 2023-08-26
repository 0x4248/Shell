/* Shell (dir.cpp)
 * A simple shell made in C++
 * Github: https://www.github.com/awesomelewis2007/shell
 * Licence: GNU General Public License v3.0
 * By: Lewis Evans
 *
 * directory helper functions
 */

#include <filesystem>
#include <iostream>
#include <string>
#include <unistd.h>

#include "colour.h"
#include "printsh.h"

/**
 * Gets the current directory
 * @returns: std::string
 */
std::string get_current_directory() {
    char cwd[1024];
    cwd[1023] = '\0';
    if (getcwd(cwd, 1023) == nullptr) {
        pr_error("getcwd() failed to get the current directory");
    }
    return cwd;
}

/**
 * Formats the current working directory string to
 * make the top most folder coloured cyan and the
 * rest of the directory coloured blue.
 * @param directory: std::string
 * @returns: std::string
 */
std::string format_current_directory(std::string directory) {
    ascii_colours::normal normal;
    ascii_colours::bold bold;
    std::string formatted_directory;
    int last_slash = directory.find_last_of("/");
    formatted_directory = directory.substr(0, last_slash + 1);
    formatted_directory = bold.blue + formatted_directory + bold.cyan;
    formatted_directory += directory.substr(last_slash + 1, directory.length());
    return formatted_directory;
}

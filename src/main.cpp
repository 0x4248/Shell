/* Shell (main.cpp)
 * A simple shell made in C++
 * Github:https://www.github.com/awesomelewis2007/shell
 *
 * Shell main file
*/

#include <iostream>
#include <string>
#include <unistd.h>


#include "colour.h"

#include "command.h"
#include "name.h"
#include "dir.h"
#include "config/config.h"

/* Define console colours */
ascii_colours::normal normal;
ascii_colours::bold bold;


/**
 * parse version
 * @returns: The version as a string
*/
std::string parse_version(){
    std::string version = std::to_string(VERSION_MAJOR) + "." + std::to_string(VERSION_MINOR) + "." + std::to_string(VERSION_PATCH);
    return version;
}

/**
 * Prints the welcome message
 * @returns: void
 */
void print_welcome(){
    std::cout << bold.green << "Welcome to " << NAME << " " << parse_version() << bold.reset << std::endl;
    std::cout << "Type 'help' for a list of commands" << std::endl;
}

/**
 * Main function
 * @param argc: int
 * @param argv: char*
 * @returns: int
 */
int main(int argc, char *argv[]) {
    print_welcome();
    std::string output;
    std::string input;
    while(true){
        std::cout << bold.green << get_username() << "@" << get_hostname() << bold.reset << ":" << format_current_directory(get_current_directory()) << bold.reset << "$ ";
        std::getline(std::cin, input);
        run_input(input);
    }
}
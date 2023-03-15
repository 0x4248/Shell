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

/* Define console colours */
ascii_colours::normal normal;
ascii_colours::bold bold;

/**
 * Prints the welcome message
 * @returns: void
 */
void print_welcome(){
    std::cout << "Welcome to awesomelewis2007's shell" << std::endl;
    std::cout << "Type 'help' for a list of commands" << std::endl;
}

/**
 * Gets the username
 * @returns: std::string
 */
std::string get_username(){
    char *username = getenv("USER");
    return username;
}
/**
 * Gets the hostname
 * @returns: std::string
 */
std::string get_hostname(){
    char hostname[1024];
    hostname[1023] = '\0';
    gethostname(hostname, 1023);
    return hostname;
}

/**
 * Gets the current directory
 * @returns: std::string
 */
std::string get_current_directory(){
    char cwd[1024];
    cwd[1023] = '\0';
    getcwd(cwd, 1023);
    return cwd;
}

/**
 * Formats the current directory string to make
 * the top most folder coloured cyan and the rest
 * of the directory coloured blue.
 * @param directory: std::string
 * @returns: std::string
 */

std::string format_current_directory(std::string directory){
    std::string formatted_directory;
    int last_slash = directory.find_last_of("/");
    formatted_directory = directory.substr(0, last_slash + 1);
    formatted_directory = bold.blue + formatted_directory + bold.cyan;
    formatted_directory += directory.substr(last_slash + 1, directory.length());
    return formatted_directory;
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
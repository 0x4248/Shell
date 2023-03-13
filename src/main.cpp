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
        std::cout << get_username() << "@" << get_hostname() << ":" << get_current_directory() << "$ ";
        std::getline(std::cin, input);
        run_input(input);
    }
}
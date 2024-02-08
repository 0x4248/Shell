/* Shell (main.cpp)
 * A simple shell made in C++
 * Github: https://www.github.com/lewisevans2007/shell
 * Licence: GNU General Public License v3.0
 * By: Lewis Evans
 *
 * Shell main file
 */

#include <cstring>
#include <iostream>
#include <string>
#include <unistd.h>

#include "colour.h"
#include "command.h"
#include "config/config.h"
#include "dir.h"
#include "name.h"
#include "os.h"

/*
 * Just in case we dont compile these in the config
 * we will define them here with default values
 */

#ifndef CONFIG_WELCOME_MESSAGE
#define CONFIG_WELCOME_MESSAGE false
#endif

#ifndef CONFIG_CUSTOM_WELCOME_MESSAGE
#define CONFIG_CUSTOM_WELCOME_MESSAGE false
#endif

#ifndef CONFIG_CUSTOM_WELCOME_MESSAGE_TEXT
#define CONFIG_CUSTOM_WELCOME_MESSAGE_TEXT "Type 'help' for a list of commands"
#endif

#ifndef CONFIG_PRINTSH_LOG_TO_FILE
#define CONFIG_PRINTSH_LOG_TO_FILE false
#endif

#ifndef CONFIG_PRINTSH_LOG_FILE_PATH
#define CONFIG_PRINTSH_LOG_FILE_PATH "shell.log"
#endif

/* Define console colours */
ascii_colours::normal normal;
ascii_colours::bold bold;

/**
 * parse version
 * Gets the version from the config and returns it as a string
 * @returns: The version as a string
 */
std::string parse_version() {
    std::string version = std::to_string(CONFIG_VERSION_MAJOR) + "." +
                          std::to_string(CONFIG_VERSION_MINOR) + "." +
                          std::to_string(CONFIG_VERSION_PATCH) + " " +
                          CONFIG_VERSION_NAME;
    return version;
}

/**
 * Prints the welcome message
 * @returns: void
 */
void print_welcome() {
    if (CONFIG_WELCOME_MESSAGE == true) {
        std::cout << bold.green << "Welcome to " << CONFIG_NAME << " ("
                  << parse_version() << " " << get_os_name() << ")"
                  << bold.reset << std::endl;
        if (CONFIG_CUSTOM_WELCOME_MESSAGE == false) {
            std::cout << "Type 'help' for a list of commands" << std::endl;
        } else {
            std::cout << CONFIG_CUSTOM_WELCOME_MESSAGE_TEXT << std::endl;
        }
    }
}

/**
 * Main entry point for shell
 * @param argc: int
 * @param argv: char*89
 * @returns: int
 */
int main(int argc, char *argv[]) {
    if (argc > 1) {
        /* Check for CLI arguments */
        if (strcmp(argv[1], "-v") == 0) {
            /* If the first CLI argument is "-v", print the version */
            std::cout << parse_version() << std::endl;
            return 0;
        }
        if (strcmp(argv[1], "--config") == 0) {
            /* If the first CLI argument is "--config", print the config */
            std::cout << "Shell configuration:" << std::endl;
            std::cout << "Name:\t\t\t" << CONFIG_NAME << std::endl;
            std::cout << "Version:\t\t" << parse_version() << std::endl;
            std::cout << "Show welcome message:\t" << CONFIG_WELCOME_MESSAGE
                      << std::endl;
            std::cout << "Log level:\t\t" << CONFIG_LOG_LEVEL << std::endl;
            std::cout << "Log to file:\t\t" << CONFIG_PRINTSH_LOG_TO_FILE
                      << std::endl;
            std::cout << "Log file path:\t\t" << CONFIG_PRINTSH_LOG_FILE_PATH
                      << std::endl;
            std::cout << "History file path:\t" << CONFIG_HISTORY_FILE_PATH
                      << std::endl;
            return 0;
        }
    }
    /* Print the welcome message */
    print_welcome();
    std::string output;
    std::string input;
    while (true) {
        /* Command line prompt */
        std::cout << bold.green << get_username() << "@" << get_hostname()
                  << bold.reset << ":"
                  << format_current_directory(get_current_directory())
                  << bold.reset << "$ ";
        /* Get the user's input */
        std::getline(std::cin, input);
        /* Run the user's input */
        run_input(input);
    }
}
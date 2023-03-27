/* Shell (printsh.cpp)
 * A simple shell made in C++
 * Github: https://www.github.com/awesomelewis2007/shell
 *
 * Shell verbose handler source file
*/
#include <iostream>
#include <string>
#include <fstream>

#include "colour.h"
#include "printsh.h"
#include "config/config.h"

/**
 * printsh - print a message to the shell
 * @message: std::string
 * @returns: void
*/
void printsh(std::string message){
    std::cout << message << std::endl;
    if (PRINTSH_LOG_TO_FILE == true){
        std::ofstream log_file;
        log_file.open(PRINTSH_LOG_FILE_PATH, std::ios::app);
        log_file << message << std::endl;
        log_file.close();
    }
}

/**
 * pr_error - print an error message to the shell
 * @message: std::string
 * @returns: void
*/
void pr_error(std::string message){
    ascii_colours::normal normal;
    ascii_colours::bold bold;
    if (LOG_LEVEL >= 1) {
        std::cerr << bold.red << "Error: " << bold.reset;
        printsh(message);
    }
}

/**
 * pr_warning - print a warning message to the shell
 * @message: std::string
 * @returns: void
*/
void pr_warning(std::string message){
    ascii_colours::normal normal;
    ascii_colours::bold bold;
    if (LOG_LEVEL >= 2) {
        std::cerr << bold.yellow << "Warning: " << bold.reset;
        printsh(message);
    }
}

/**
 * pr_info - print an info message to the shell
 * @message: std::string
 * @returns: void
*/
void pr_info(std::string message){
    ascii_colours::normal normal;
    ascii_colours::bold bold;
    if (LOG_LEVEL >= 3) {
        std::cerr << bold.blue << "Info: " << bold.reset;
        printsh(message);
    }
}

/**
 * pr_debug - print a debug message to the shell
 * @message: std::string
 * @returns: void
*/
void pr_debug(std::string message){
    ascii_colours::normal normal;
    ascii_colours::bold bold;
    if (LOG_LEVEL >= 4) {
        std::cerr << bold.magenta << "Debug: " << bold.reset;
        printsh(message);
    }
}


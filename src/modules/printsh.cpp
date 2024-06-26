/* Shell (printsh.cpp)
 * A simple shell made in C++
 * Github: https://www.github.com/0x4248/shell
 * Licence: GNU General Public License v3.0
 * By: 0x4248
 *
 * Shell verbose handler source file
 */
#include <fstream>
#include <iostream>
#include <string>

#include "colour.h"
#include "config/config.h"
#include "printsh.h"
#include "printsh_log.h"

#ifndef CONFIG_PRINTSH_LOG_TO_FILE
#define CONFIG_PRINTSH_LOG_TO_FILE false
#endif

#ifndef CONFIG_PRINTSH_LOG_FILE_PATH
#define CONFIG_PRINTSH_LOG_FILE_PATH "shell.log"
#endif

/**
 * printsh - print a message to the shell
 * @message: std::string
 * @returns: void
 */
void printsh(std::string message) {
    std::cout << message << std::endl;
    pr_message_store(message, "printsh");
    if (CONFIG_PRINTSH_LOG_TO_FILE == true) {
        std::ofstream log_file;
        log_file.open(CONFIG_PRINTSH_LOG_FILE_PATH, std::ios::app);
        log_file << message << std::endl;
        log_file.close();
    }
}

/**
 * pr_error - print an error message to the shell
 * @message: std::string
 * @returns: void
 */
void pr_error(std::string message) {
    ascii_colours::normal normal;
    ascii_colours::bold bold;
    pr_message_store(message, "error");
    if (CONFIG_LOG_LEVEL >= 1) {
        std::cerr << bold.red << "Error: " << bold.reset;
        printsh(message);
    }
}

/**
 * pr_warning - print a warning message to the shell
 * @message: std::string
 * @returns: void
 */
void pr_warning(std::string message) {
    ascii_colours::normal normal;
    ascii_colours::bold bold;
    pr_message_store(message, "warning");
    if (CONFIG_LOG_LEVEL >= 2) {
        std::cerr << bold.yellow << "Warning: " << bold.reset;
        printsh(message);
    }
}

/**
 * pr_info - print an info message to the shell
 * @message: std::string
 * @returns: void
 */
void pr_info(std::string message) {
    ascii_colours::normal normal;
    ascii_colours::bold bold;
    pr_message_store(message, "info");
    if (CONFIG_LOG_LEVEL >= 3) {
        std::cerr << bold.blue << "Info: " << bold.reset;
        printsh(message);
    }
}

/**
 * pr_debug - print a debug message to the shell
 * @message: std::string
 * @returns: void
 */
void pr_debug(std::string message) {
    ascii_colours::normal normal;
    ascii_colours::bold bold;
    pr_message_store(message, "debug");
    if (CONFIG_LOG_LEVEL >= 4) {
        std::cerr << bold.magenta << "Debug: " << bold.reset;
        printsh(message);
    }
}

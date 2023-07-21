/* Shell (printsh_log.cpp)
 * A simple shell made in C++
 * Github: https://www.github.com/awesomelewis2007/shell
 * Licence: GNU General Public License v3.0
 * By: Lewis Evans
 *
 * This file stores the log messages for when the user runs pr_log
 */

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "colour.h"
#include "config/config.h"
#include "printsh.h"
#include "printsh_log.h"

std::vector<std::string> printsh_log;
std::vector<std::string> pr_error_log;
std::vector<std::string> pr_warning_log;
std::vector<std::string> pr_info_log;
std::vector<std::string> pr_debug_log;

/**
 * pr_message_store
 * @message: std::string
 * @level: std::string
 * @returns: int
 *
 * This function stores the message in the correct log vector
 * Levels:
 * - printsh
 * - error
 * - warning
 * - info
 * - debug
 */
int pr_message_store(std::string message, std::string level) {
    if (level == "printsh") {
        printsh_log.push_back(message);
    } else if (level == "error") {
        pr_error_log.push_back(message);
    } else if (level == "warning") {
        pr_warning_log.push_back(message);
    } else if (level == "info") {
        pr_info_log.push_back(message);
    } else if (level == "debug") {
        pr_debug_log.push_back(message);
    } else {
        /* If we dont know the level, return 1 */
        return 1;
    }
    return 0;
}

/**
 * pr_log_read
 * @level: std::string
 * @returns: vector <std::string>
 */
std::vector<std::string> pr_log_read(std::string level) {
    if (level == "printsh") {
        return printsh_log;
    } else if (level == "error") {
        return pr_error_log;
    } else if (level == "warning") {
        return pr_warning_log;
    } else if (level == "info") {
        return pr_info_log;
    } else if (level == "debug") {
        return pr_debug_log;
    } else {
        return {};
    }
}
/* Shell (printsh_log.cpp)
 * A simple shell made in C++
 * Github: https://www.github.com/0x4248/shell
 * Licence: GNU General Public License v3.0
 * By: 0x4248
 *
 * This file stores the log messages for when the user runs pr_log
 */

#include <string>
#include <vector>

/**
 * pr_message_store
 * @message: std::string
 * @level: std::string
 * @returns: int
 *
 * This function stores the message in the correct log vector
 * Levels:
 * - printsh (Standard output)
 * - error
 * - warning
 * - info
 * - debug
 */
int pr_message_store(std::string message, std::string level);

/**
 * pr_log_read
 * @level: std::string
 * @returns: vector <std::string>
 */
std::vector<std::string> pr_log_read(std::string level);
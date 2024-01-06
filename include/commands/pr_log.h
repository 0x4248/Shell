/* Shell (pr_log.cpp)
 * A simple shell made in C++
 * Github: https://www.github.com/lewisevans2007/shell
 * Licence: GNU General Public License v3.0
 * By: Lewis Evans
 *
 * Shell pr_log command source file
 */

#include <string>
#include <vector>

/**
 * pr_log_command
 * @args: std::string
 * @returns: int
 *
 * This function reads the printsh log using the pr_log_read function
 */
int pr_log_command(std::string args);
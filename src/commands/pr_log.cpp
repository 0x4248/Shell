/* Shell (pr_log.cpp)
 * A simple shell made in C++
 * Github: https://www.github.com/awesomelewis2007/shell
 * Licence: GNU General Public License v3.0
 * By: Lewis Evans
 *
 * Shell pr_log command source file
 */

#include <string>
#include <vector>

#include "argparse.h"
#include "printsh.h"
#include "printsh_log.h"

#include "config/config.h"

/**
 * pr_log_command
 * @args: std::string
 * @returns: int
 *
 * This function reads the printsh log using the pr_log_read function
 */
int pr_log_command(std::string args) {

    std::vector<std::string> args_split = argparse(args);
    std::string level;
    if (args_split.size() == 1) {
        level = "printsh";
    } else if (args_split.size() == 2) {
        level = args_split[1];
    } else {
        pr_error("Invalid number of arguments");
        return 1;
    }
    std::vector<std::string> log = pr_log_read(level);
    if (log.size() == 0) {
        printsh("No log messages found");
        return 0;
    }
    for (int i = 0; i < log.size(); i++) {
        printsh("[" + level + "] " + log[i]);
    }
    return 0;
}
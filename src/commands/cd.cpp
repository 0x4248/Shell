/* Shell (cd.h)
 * A simple shell made in C++
 * Github: https://www.github.com/awesomelewis2007/shell
 * Licence: GNU General Public License v3.0
 * By: Lewis Evans
 *
 * Change directory command header file
 */

#include <filesystem>
#include <iostream>

#include "err_no.h"
#include "printsh.h"

#include "commands/cd.h"

/**
 * Parse the cd arguments
 * @param input: std::string
 * @returns: std::string
 *
 * If the user types cd ~ then it will return
 * the home directory location
 *
 * e.g cd ~ -> /root/
 *
 */
std::string parse_input(std::string input) {
    if (input == "~") {
        return getenv("HOME");
    } else {
        return input;
    }
}

/**
 * Change the current working directory
 * @param dir: std::string
 * @returns: int
 *
 * Returns 0 on success, and DIR_NOT_FOUND on error
 */
int change_dir(std::string dir) {
    /* Change the current working directory*/
    try {
        std::filesystem::current_path(dir);
        return 0;
    } catch (std::filesystem::filesystem_error &e) {
        return DIR_NOT_FOUND;
    } catch (std::exception &e) {
        return ERROR;
    }
}

void cd_command(std::string dir) {
    dir = parse_input(dir);
    int status = change_dir(dir);
    if (status == DIR_NOT_FOUND) {
        pr_error(
            dir +
            ": Could not change directory. Check if the directory exists.");
    }
    if (status == ERROR) {
        pr_error("Could not change directory. An error occurred.");
    }
}
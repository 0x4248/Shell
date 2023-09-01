/* Shell (history.cpp)
 * A simple shell made in C++
 * Github: https://www.github.com/awesomelewis2007/shell
 * Licence: GNU General Public License v3.0
 * By: Lewis Evans
 *
 * Shell history command source file
 */

#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "argparse.h"
#include "commands/history.h"
#include "name.h"
#include "printsh.h"

#include "config/config.h"

/**
 * get_history - Gets the shell history
 *
 * Gets the shell history from the history file
 * and returns it as a string each line is separated
 * by a newline character
 *
 * @returns: std::string
 */
std::string get_history() {
    std::string history_path =
        "/home/" + get_username() + "/" + HISTORY_FILE_PATH;
    std::ifstream history_file(history_path);
    std::string line;
    std::string history;
    if (history_file.is_open()) {
        while (getline(history_file, line)) {
            history += line + "\n";
        }
        history_file.close();
    } else {
        return "ERROR";
    }
    return history;
}

/**
 * print_last - Prints the last command ran
 * @returns: int
 */
int print_last(std::string args) {
    std::string history = get_history();
    if (history == "ERROR") {
        pr_error("Could not open history file");
        return 1;
    } else {
        std::vector<std::string> history_lines;
        std::stringstream ss(history);
        std::string line;
        while (std::getline(ss, line, '\n')) {
            history_lines.push_back(line);
        }
        if (history_lines.size() == 0) {
            pr_error("History is empty");
            return 1;
        } else {
            std::string last_command = history_lines.back();
            printsh(last_command);
            return 0;
        }
    }
}

/**
 * print_all - Prints the shell history
 * @returns: int
 */
int print_all(std::string args) {
    std::string history = get_history();
    if (history == "ERROR") {
        pr_error("Could not open history file");
        return 1;
    } else {
        printsh(history);
        return 0;
    }
}

/**
 * Prints the shell history
 * @returns: void
 */
int history_command(std::string args) {
    int ret = 0;
    std::vector<std::string> args_list = argparse(args);
    args_list.erase(args_list.begin());
    if (args_list.size() == 0) {
        ret = print_all(args);
    } else {
        if (args_list[0] == "--last") {
            ret = print_last(args);
        }
    }
    return ret;
}

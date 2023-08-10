/* Shell (command.cpp)
 * A simple shell made in C++
 * Github: https://www.github.com/awesomelewis2007/shell
 * Licence: GNU General Public License v3.0
 * By: Lewis Evans
 *
 * Command runner source file
 */

#include <array>
#include <cstdio>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>

#include "command.h"
#include "name.h"
#include "printsh.h"

#include "commands/cd.h"
#include "commands/help.h"
#include "commands/history.h"
#include "commands/pr_log.h"

std::string exec(const char *cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

/**
 * Shell history saver
 * This function saves the user's input
 * to the history file
 * @param input: std::string
 * @returns: void
 */
void save_to_history(const std::string &input) {
    const auto history_path =
        std::filesystem::path("/home") / get_username() / ".shell_history";
    std::ofstream history_file(history_path, std::ios::app);
    if (!history_file.is_open()) {
        throw std::runtime_error("Failed to open history file");
    }
    history_file << input << '\n';
    if (!history_file) {
        throw std::runtime_error("Failed to write to history file");
    }
}
/**
 * Shell main input runner
 * This function runs the command that
 * the user inputs.
 * @param input: std::string
 * @returns: void
 */
void run_input(std::string input) {
    if (input == "help") {
        help();
    } else if (input == "exit") {
        exit(0);
    } else if (input.substr(0, 2) == "cd") {
        if (input.length() == 2) {
            /**
             * If the user inputs 'cd' without a directory,
             * then change the directory to the home directory
             */
            cd_command(getenv("HOME"));
        } else {
            cd_command(input.substr(3, input.length()));
        }
    } else if (input.substr(0, 7) == "history") {
        history_command(input);
    } else if (input.substr(0, 6) == "pr_log") {
        pr_log_command(input);
    } else {
        std::string output = exec(input.c_str());
        std::cout << output;
    }
    save_to_history(input);
}
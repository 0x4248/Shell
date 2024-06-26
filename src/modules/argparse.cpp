/* Shell (argparse.cpp)
 * A simple shell made in C++
 * Github: https://www.github.com/0x4248/shell
 * Licence: GNU General Public License v3.0
 * By: 0x4248
 *
 * Argument parser source file
 *
 * This file contains the argument parser for the shell
 *
 * When the user enters a command the command needs to be parsed
 * so the commands can easily get the arguments and options without
 * needing to create a argument parser for each command
 */

#include <iostream>
#include <string>
#include <vector>

#include "argparse.h"
#include "config/config.h"
#include "printsh.h"

/**
 * argparse - Parses the arguments and options
 *
 * @example: If the arguments and options are "arg1 arg2 -o arg3"
 *          The function will return a vector with the following:
 *          ["arg1", "arg2", "-o", "arg3"]
 *
 * @param args The arguments and options
 * @returns: A vector of the arguments and options
 */
std::vector<std::string> argparse(std::string args) {
    std::vector<std::string> parsed_args;
    std::string arg = "";
    for (int i = 0; i < args.length(); i++) {
        if (args[i] == ' ') {
            if (arg != "") {
                parsed_args.push_back(arg);
                arg = "";
            }
        } else {
            arg += args[i];
        }
    }
    if (arg != "") {
        parsed_args.push_back(arg);
    }
    return parsed_args;
}
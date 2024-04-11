/* Shell (command.h)
 * A simple shell made in C++
 * Github: https://www.github.com/0x4248/shell
 * Licence: GNU General Public License v3.0
 * By: 0x4248
 *
 * Command runner header file
 */

#include <filesystem>
#include <iostream>
#include <string>

/**
 * Shell main input runner
 * This function runs the command that
 * the user inputs.
 * @param input: std::string
 * @returns: void
 */
void run_input(std::string input);
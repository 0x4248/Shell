/* Shell (command.h)
 * A simple shell made in C++
 * Github: https://www.github.com/awesomelewis2007/shell
 * License: GPL-3.0
 * By: Lewis Evans
 *
 * Command runner header file
*/

#include <iostream>
#include <string>
#include <filesystem>

/**
 * Shell main input runner
 * This function runs the command that 
 * the user inputs. 
 * @param input: std::string
 * @returns: void
*/
void run_input(std::string input);
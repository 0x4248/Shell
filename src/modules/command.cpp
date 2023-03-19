/* Shell (command.cpp)
 * A simple shell made in C++
 * Github: https://www.github.com/awesomelewis2007/shell
 *
 * Command runner source file
*/

#include <iostream>
#include <string>
#include <filesystem>

#include "command.h"

#include "commands/help.h"
#include "commands/cd.h"

/**
 * Shell main input runner
 * This function runs the command that 
 * the user inputs. 
 * @param input: std::string
 * @returns: void
*/
void run_input(std::string input){
    if (input == "help"){
        help();
    }
    else if (input == "exit"){
        exit(0);
    }
    else if (input.substr(0, 2) == "cd"){
        if (input.length() == 2){
            /**
             * If the user inputs 'cd' without a directory,
             * then change the directory to the home directory
            */
            cd(getenv("HOME"));
        }
        else {
            cd(input.substr(3, input.length()));
        }
    }
    else{
        system(input.c_str());
    }
}
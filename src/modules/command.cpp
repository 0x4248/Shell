/* Shell (command.cpp)
 * A simple shell made in C++
 * Github: https://www.github.com/awesomelewis2007/shell
 *
 * Command runner source file
*/

#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>

#include "command.h"
#include "name.h"
#include "printsh.h"

#include "commands/help.h"
#include "commands/cd.h"
#include "commands/history.h"

/**
 * Shell history saver
 * This function saves the user's input
 * to the history file
 * @param input: std::string
 * @returns: void
*/
void save_to_history(std::string input){
    std::ofstream history_file;
    std::string history_path = "/home/"+get_username()+"/.shell_history";
    history_file.open(history_path, std::ios::app);
    history_file << input << std::endl;
    history_file.close();
}

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
            cd_command(getenv("HOME"));
        }
        else {
            cd_command(input.substr(3, input.length()));
        }
    }
    else if (input.substr(0, 7) == "history"){
        history_command(input);
    }
    else{
        system(input.c_str());
    }
    save_to_history(input);
}
/* Shell (history.cpp)
 * A simple shell made in C++
 * Github: https://www.github.com/awesomelewis2007/shell
 *
 * Shell history command source file
*/

#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>

#include "commands/history.h"
#include "printsh.h"
#include "name.h"

#include "config/config.h"

/**
 * Prints the shell history
 * @returns: void
*/
int history_command(std::string args){
    std::string history_path = "/home/"+get_username()+"/"+HISTORY_FILE_PATH;
    std::ifstream history_file(history_path);
    std::string line;
    if(history_file.is_open()){
        while(getline(history_file, line)){
            std::cout << line << std::endl;
        }
        history_file.close();
    }else{
        pr_error("Could not open history file");
        return 1;
    }
    return 0;
}

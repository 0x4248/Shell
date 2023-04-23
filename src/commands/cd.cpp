/* Shell (cd.h)
 * A simple shell made in C++
 * Github: https://www.github.com/awesomelewis2007/shell
 * Licence: GPL-3.0
 * By: Lewis Evans
 *
 * Change directory command header file
*/

#include <iostream>
#include <filesystem>

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
std::string parse_input(std::string input){
    if(input == "~"){
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
int change_dir(std::string dir){
    /* Change the current working directory*/
    if(!std::filesystem::exists(dir)){
        /* If the directory does not exist, then return an error*/
        return DIR_NOT_FOUND;
    } else {
        /* If the directory exists, then change the current working directory*/
        std::filesystem::current_path(dir);
        return 0;
    }
}

void cd_command(std::string dir){
    dir = parse_input(dir);
    int status = change_dir(dir);
    if(status == DIR_NOT_FOUND){
        pr_error(dir + ": No such file or directory");
    }
}
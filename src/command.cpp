// Shell (command.cpp)
// A simple shell made in C++
// Github: https://www.github.com/awesomelewis2007/shell
//
// Command runner source file

#include <iostream>
#include <string>

#include "command.h"
#include "help.h"
void run_input(std::string input){
    if (input == "help"){
        help();
    }
    else if (input == "exit"){
        exit(0);
    }
    else{
        system(input.c_str());
    }
}
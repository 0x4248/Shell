#include <iostream>
#include <string>
#include <cstdio>
#include <memory>
#include <stdexcept>
#include <array>
#include <stdlib.h>

std::string VERSION = "0.0.1";

//https://stackoverflow.com/questions/478898/how-do-i-execute-a-command-and-get-the-output-of-the-command-within-c-using-po#:~:text=%23include%20%3Ciostream%3E%0A%23include%20%3Cstdexcept,throw%3B%0A%20%20%20%20%7D%0A%20%20%20%20pclose(pipe)%3B%0A%20%20%20%20return%20result%3B%0A%7D
std::string exec(const char* cmd) {
    char buffer[128];
    std::string result = "";
    FILE* pipe = popen(cmd, "r");
    if (!pipe) throw std::runtime_error("popen() failed!");
    try {
        while (fgets(buffer, sizeof buffer, pipe) != NULL) {
            result += buffer;
        }
    } catch (...) {
        pclose(pipe);
        throw;
    }
    pclose(pipe);
    return result;
}

void help(){
    std::cout << "Usage: " << std::endl;
    std::cout << "  -v: Print version" << std::endl;
    std::cout << "  -h: Print help" << std::endl;
}

void parse(std::string command)
{
    //if command is help then call help function
    if (command == "help")
    {
        help();
    } else if (command == "exit" || command == "quit")
    {
        exit(0);
    } else if (command == "version"){
        std::cout << "Version: " << VERSION << std::endl;
    } else {
        std::string result = exec(command.c_str());
        std::cout << result;
    }

}

int shell_loop() {
    while(true){
        std::string command;
        std::cout << "> ";
        std::getline(std::cin, command);
        parse(command);
    }
    return 1;
}

int main(int argc, char **argv) {
    if(argc > 1 && std::string(argv[1]) == "-v"){
        std::cout << "Version: " << VERSION << std::endl;
        return 0;
    } else if (argc > 1 && std::string(argv[1]) == "-h"){
        help();
        return 0;
    }
    shell_loop();
    return 0;
}


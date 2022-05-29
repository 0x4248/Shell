#include <iostream>
#include <string>
#include <cstdio>
#include <memory>
#include <stdexcept>
#include <array>
#include <stdlib.h>

#include "commands.h"

void help(){
    std::cout << "Usage: " << std::endl;
    std::cout << "  -v: Print version" << std::endl;
    std::cout << "  -h: Print help" << std::endl;
}
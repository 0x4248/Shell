/* Shell (history.cpp)
 * A simple shell made in C++
 * Github: https://www.github.com/lewisevans2007/shell
 * Licence: GNU General Public License v3.0
 * By: Lewis Evans
 *
 * OS Determination source file
 */

#include <string>

#include "os.h"
/**
 * getOsName - Gets the name of the OS
 * @returns: std::string
 */
std::string get_os_name() {
#ifdef _WIN32
    return "Windows 32-bit";
#elif _WIN64
    return "Windows 64-bit";
#elif __APPLE__ || __MACH__
    return "Mac OSX";
#elif __linux__
    return "Linux";
#elif __FreeBSD__
    return "FreeBSD";
#elif __unix || __unix__
    return "Unix";
#else
    return "Other";
#endif
}
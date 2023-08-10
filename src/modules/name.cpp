/* Shell (name.cpp)
 * A simple shell made in C++
 * Github: https://www.github.com/awesomelewis2007/shell
 * Licence: GNU General Public License v3.0
 * By: Lewis Evans
 *
 * Functions for getting usernames and hostnames
 */

#include <iostream>
#include <string>
#include <unistd.h>

/**
 * Gets the username
 * @returns: std::string
 */
std::string get_username()
{
    char *username = getenv("USER");
    return username;
}

/**
 * Gets the hostname
 * @returns: std::string
 */
std::string get_hostname()
{
    char hostname[1024];
    hostname[1023] = '\0';
    gethostname(hostname, 1023);
    return hostname;
}

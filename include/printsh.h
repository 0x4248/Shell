/* Shell (printsh.h)
 * A simple shell made in C++
 * Github: https://www.github.com/lewisevans2007/shell
 * Licence: GNU General Public License v3.0
 * By: Lewis Evans
 *
 * Shell verbose handler header file
 */

#include <string>

/**
 * printsh - print a message to the shell
 * @message: std::string
 * @returns: void
 *
 * All standard outputs should be done through this function
 */
void printsh(std::string message);

/**
 * pr_error - print an error message to the shell
 * @message: std::string
 * @returns: void
 */
void pr_error(std::string message);

/**
 * pr_warning - print a warning message to the shell
 * @message: std::string
 * @returns: void
 */
void pr_warning(std::string message);

/**
 * pr_info - print an info message to the shell
 * @message: std::string
 * @returns: void
 */
void pr_info(std::string message);

/**
 * pr_debug - print a debug message to the shell
 * @message: std::string
 * @returns: void
 */
void pr_debug(std::string message);
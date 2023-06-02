/* Shell (config.h)
 * A simple shell made in C++
 * Github: https://www.github.com/awesomelewis2007/shell
 * Licence: GNU General Public License v3.0
 * By: Lewis Evans
 *
 * Shell configuration header file
 * This file contains most of the configuration for the shell
 */

/* Shell version */
#define VERSION_MAJOR 1
#define VERSION_MINOR 2
#define VERSION_PATCH 0
#define VERSION_NAME "Beta"

/* Shell general */
#define NAME "Shell++"
#define SHOW_WELCOME_MESSAGE true
#define CUSTOM_WELCOME_MESSAGE false
#define CUSTOM_WELCOME_MESSAGE_TEXT "Type 'help' for a list of commands"

/* Printsh */

/**
 * LOG_LEVEL - the log level
 * 0 - no logging
 * 1 - errors
 * 2 - errors and warnings
 * 3 - errors, warnings and info
 * 4 - errors, warnings, info and debug
 */
#define LOG_LEVEL 2

/**
 * PRINTSH_LOG_TO_FILE - whether to log to a file
 * PRINTSH_LOG_FILE_PATH - the path to the log file
 */
#define PRINTSH_LOG_TO_FILE false
#define PRINTSH_LOG_FILE_PATH "shell.log"

/* History */

#define HISTORY_FILE_PATH ".shell_history"
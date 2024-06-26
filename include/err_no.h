/* Shell (errno.h)
 * A simple shell made in C++
 * Github: https://www.github.com/0x4248/shell
 * Licence: GNU General Public License v3.0
 * By: 0x4248
 *
 * Error codes header file
 */

/* Standard error codes */
#define ERROR 1
#define MAJOR_ERROR 4

/* File error codes */
#define FILE_NOT_FOUND 2
#define FILE_UNREADABLE 3

/* Directory error codes */
#define DIR_NOT_FOUND 5
#define DIR_UNREADABLE 6

/* Command error codes */
#define COMMAND_NOT_FOUND 7

/* Function error codes */
#define EINVAL 8
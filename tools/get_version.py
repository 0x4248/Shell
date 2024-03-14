# Shell (get_version.py)
# A simple shell made in C++
# Github: https://www.github.com/lewisevans2007/shell
# Licence: GNU General Public License v3.0
# By: Lewis Evans
#
# This file returns the version of the shell from the config.h file
# This program is called from the Makefile to get the version of the shell

import os
import re

def get_version():
    with open(os.path.join(os.path.dirname(__file__), "..", "include", "config", "config.h"), "r") as f:
        data = f.read()
        major = re.search(r"#define\s+CONFIG_VERSION_MAJOR\s+(\d+)", data).group(1)
        minor = re.search(r"#define\s+CONFIG_VERSION_MINOR\s+(\d+)", data).group(1)
        patch = re.search(r"#define\s+CONFIG_VERSION_PATCH\s+(\d+)", data).group(1)
        name = re.search(r"#define\s+CONFIG_VERSION_NAME\s+\"(.+)\"", data).group(1)
        return f"{major}.{minor}.{patch} {name}"
    
if __name__ == "__main__":
    print(get_version())

# Shell (Makefile)
# A simple shell made in C++
# Github:https://www.github.com/awesomelewis2007/shell
# Licence: GNU General Public License v3.0
# By: Lewis Evans
#
# Main makefile 

CC = g++
CFLAGS = -std=c++17 -Os -I include

SRC = $(wildcard src/*.cpp) $(wildcard src/modules/*.cpp) $(wildcard src/commands/*.cpp)
OBJ = $(SRC:.cpp=.o)	

BIN = bin
OUTPUT = shell

all: init shell

shell: $(OBJ)
	@echo "LD\t$@"
	$(CC) $(CFLAGS) -o $(BIN)/$(OUTPUT) $(OBJ)

%.o: %.cpp
	@echo "CC\t$@"
	$(CC) $(CFLAGS) -o $@ -c $<

init:
	@echo "MKDIR\t" $(BIN)
	@mkdir -p $(BIN)

clean:
	@echo "RM" $(OBJ) $(BIN)/$(OUTPUT)
	@rm -f $(OBJ) $(BIN)/$(OUTPUT)
	@echo "RM CMakeFiles CMakeCache.txt cmake_install.cmake"
	@rm -rf CMakeFiles CMakeCache.txt cmake_install.cmake

clean_all: clean
	@echo "RM" $(BIN)
	@rm -f $(OBJ) shell
	@rm -rf $(BIN)

help:
	@echo "Shell++ Makefile"
	@echo "Usage: make [target]"
	@echo "Targets:"
	@echo "  all:        Build the shell"
	@echo "  init:	      Create the bin folder"
	@echo "  clean:      Removes the build files"
	@echo "  clean_all   Removes the build files and the bin folder"
	@echo "  help:       Display this help message"

.SILENT:

.PHONY: all clean

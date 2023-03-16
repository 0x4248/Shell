# Shell (Makefile)
# A simple shell made in C++
# https://www.github.com/awesomelewis2007/shell


CC = g++

CFLAGS = 
STD = 

SRC = src

BIN = bin

LIB = lib

INCLUDE = include/

OUTPUT = $(BIN)/shell

include CFLAGS.conf
include STD.conf

all: init compile run

init:
	rm -rf bin
	mkdir bin

compile:
	$(CC) $(CFLAGS) -std=$(STD) $(SRC)/*.cpp $(SRC)/modules/*.cpp  -o $(OUTPUT) -I $(LIB) -I $(INCLUDE) $(INCLUDE)/commands/cd.h

run:
	./$(OUTPUT)

clean:
	rm -rf bin


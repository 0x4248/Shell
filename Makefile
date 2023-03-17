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

FILES = $(SRC)/*.cpp $(SRC)/modules/*.cpp $(SRC)/commands/*.cpp

include CFLAGS.conf
include STD.conf

all: init compile run

init:
	rm -rf bin
	mkdir bin

compile:
	$(CC) $(CFLAGS) -std=$(STD) $(FILES) -o $(OUTPUT) -I $(LIB) -I $(INCLUDE)

run:
	./$(OUTPUT)

clean:
	rm -rf bin


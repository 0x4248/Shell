# Shell (Makefile)
# A simple shell made in C++
# https://www.github.com/awesomelewis2007/shell


CC = g++

CFLAGS = 
STD = 

SRC = src

BIN = bin

LIB = lib

OUTPUT = $(BIN)/shell

include CFLAGS.conf
include STD.conf

all: init compile run

init:
	rm -rf bin
	mkdir bin

compile:
	$(CC) $(CFLAGS) -std=$(STD) $(SRC)/*.cpp -o $(OUTPUT) -I $(LIB)

run:
	./$(OUTPUT)

clean:
	rm -rf bin


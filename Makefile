#
# Makefile
# @author Fabio Marciano
# @version 0.0.1
#

# OBJS: specifies which files to compile as part of the project
OBJS = src/main.cpp

# CC: specifies which compiler to use
CC = g++

# COMPILER_FLAGS: specifies the additional compilation options
COMPILER_FLAGS = -Wall

# LINKER_FLAGS: specifies the libraries to linking against
LINKER_FLAGS = -lSDL2

# OBJ_NAME: specifies the name of output
OBJ_NAME = bin/main

#This is the target that compiles our executable
all: $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

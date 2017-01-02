COMPILER = g++
FLAGS =-w -ggdb -std=c++11
OUTPUT_DIR = bin/
SOURCE_DIR = source/
all: matrix
	
matrix: $(SOURCE_DIR)matrix.cpp
	$(COMPILER) $(FLAGS) $(SOURCE_DIR)matrix.cpp -o $(OUTPUT_DIR)matrix.o


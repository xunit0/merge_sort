# The compiler to use
CXX = g++

# Compiler flags:
# -Wall = show all warnings
# -O2   = optimize the code
# -std=c++11 = use C++11 standard
CXXFLAGS = -Wall -O2 -std=c++11

# Name of the program we want to build
TARGET = merge_sort

# Source files (you can add more later)
SRC = merge_sort.cpp

# Default target (what 'make' builds if you just type 'make')
all: $(TARGET)

# How to build the program from source files
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# 'make clean' removes the program so we can start fresh
clean:
	rm -f $(TARGET)

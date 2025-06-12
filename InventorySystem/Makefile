# Makefile for InventorySystem

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

# Target name
TARGET = main

# Source files
SRCS = main.cpp item.cpp csv_utils.cpp

# Object files (replace .cpp with .o)
OBJS = $(SRCS:.cpp=.o)

# Build target
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Clean up compiled files
clean:
	rm -f $(TARGET) $(OBJS)

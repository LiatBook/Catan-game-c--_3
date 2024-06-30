# bookliat@gmail.com
CXX = g++
CXXFLAGS = -Wall -std=c++17 -g

# Target executable name
TARGET = main

# Source files
SRCS = catan.cpp player.cpp board.cpp 
MAIN_SRC = main.cpp
TEST_SRCS = TestCounter.cpp Test.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)
MAIN_OBJ = $(MAIN_SRC:.cpp=.o)
TEST_OBJS = $(TEST_SRCS:.cpp=.o)

# Header files
HDRS = board.hpp catan.hpp player.hpp card.hpp

# Default target
all: $(TARGET)

# Link main object files to create the executable
$(TARGET): $(OBJS) $(MAIN_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files into object files
%.o: %.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Test target
test: $(TEST_OBJS) $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o test

# Tidy target to run clang-tidy on source files
tidy:
	clang-tidy $(SRCS) $(MAIN_SRC) $(TEST_SRCS) -- -I.

# Valgrind target to check memory leaks
valgrind: $(TARGET)
	valgrind --leak-check=full --track-origins=yes --error-exitcode=1 ./$(TARGET)

# Clean target to remove generated files
clean:
	rm -f $(OBJS) $(MAIN_OBJ) $(TARGET) $(TEST_OBJS) test

.PHONY: all clean tidy valgrind test

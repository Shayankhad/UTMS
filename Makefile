# Compiler
CXX := g++

# Compiler flags
CXXFLAGS := -std=c++20 -Wall -Wextra -Iinclude -MMD -MP -m64

# Source and build directories
SRC_DIR := src
BUILD_DIR := build

# Create a list of source files and corresponding object files
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRC_FILES))

# Dependency files
DEP_FILES := $(OBJ_FILES:.o=.d)

# Executable name
TARGET := a.exe

# Default target
all: $(TARGET)

# Link object files to create the final executable
$(TARGET): $(OBJ_FILES)
	$(CXX) $(OBJ_FILES) -o $(TARGET) -m64

# Compile source files to object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Include dependency files if they exist
-include $(DEP_FILES)

# Run the program with specified command-line arguments
run: $(TARGET)
	./$(TARGET) files/majors.csv files/students.csv files/courses.csv files/professors.csv

# Clean up build files
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

# Phony targets
.PHONY: all clean run

# Change the commands that needs to be used for Windows and Unix systems
ifeq ($(OS),Windows_NT)
    EXE_EXT = .exe
    MKDIR = mkdir
    RM = rmdir /S /Q
	SEP = \\
else
    EXE_EXT = 
    MKDIR = mkdir -p
    RM = rm -rf
	SEP = /
endif

# Source files
SOURCES = $(wildcard *.cpp)
HEADERS = $(wildcard include/*.hpp)

# Compiler and flags
CC = g++
CFLAGS = -Wall -Wextra -std=c++17 -O3 -funroll-loops -Iinclud

# Directory
TARGET_DIR = target
BIN_DIR = $(TARGET_DIR)$(SEP)bin
OBJ_DIR = $(TARGET_DIR)$(SEP)obj

# Object files
OBJECTS = $(patsubst %.cpp,$(OBJ_DIR)$(SEP)%.o,$(SOURCES))

# Target executable
TARGET = $(BIN_DIR)$(SEP)main$(EXE_EXT)

# Default rule to run the program
default: run
all: $(TARGET)

# Rule to link the object files to create the executable
$(TARGET): $(OBJECTS) | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

# Rule to compile the .cpp files into .o files
$(OBJ_DIR)$(SEP)%.o: %.cpp $(HEADERS) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
	$(CC) -MM -MT $@ -MF $(patsubst %.o,%.d,$@) $<

# Include dependency files if they exist
-include $(OBJECTS:.o=.d)

# Rule to create the target directories if they don't exist
$(BIN_DIR) $(OBJ_DIR):
	$(MKDIR) $@

# Rule to clean up the compiled files
clean:
	$(RM) $(TARGET_DIR)

# Rule to run the program
run: $(TARGET)
	.$(SEP)$(TARGET)

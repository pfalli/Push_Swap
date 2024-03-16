# Compiler
CC := gcc

# Compiler flags
CFLAGS := -Wall -Wextra -Werror

# Source files
SRCS := main.c file1.c file2.c

# Object files
OBJS := $(SRCS:.c=.o)

# Target executable
TARGET := myprogram

# Default target
all: $(TARGET)

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Link object files into the target executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Clean up object files and the target executable
clean:
	rm -f $(OBJS) $(TARGET)
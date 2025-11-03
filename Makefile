# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -I.

# Library source files and objects
LIB_SRC = EasyStr.c
LIB_OBJ = $(LIB_SRC:.c=.o)
LIB_TARGET = libeasystr.a

# Target: 'all' (default)
# Builds the library
all: $(LIB_TARGET)

# Target: 'lib'
# Builds only the static library
$(LIB_TARGET): $(LIB_OBJ)
	ar rcs $@ $^

# Target: 'clean'
# Removes all compiled files
clean:
	rm -f $(LIB_OBJ) $(LIB_TARGET)

# Pattern rule to compile .c files to .o (object) files
%.o: %.c EasyStr.h
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean
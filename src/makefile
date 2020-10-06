# Name of the project
PROJ_NAME=sortlib

# .c files
C_SOURCE=$(wildcard * .c)

# .h files
H_SOURCE=$(wildcard * .h)

# .o files
OBJ=$(C_SOURCE:.c=.o)

# Compiler
CC=gcc

# Flags
CC_FLAGS= -O3 -c

################################
# Compilation
################################

all: $(PROJ_NAME)

$(PROJ_NAME): $(OBJ) clean
	ar -cvq libsortlib.a

%.o: %.c %.h
	$(CC) -o $@ $< $(CC_FLAGS)

clean:
	@echo "clean project"
	del /Q /F *.o
	@echo "clean completed"
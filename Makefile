CC = gcc
CFLAGS = -std=c23 -O2 -Wall -Wextra -I./include

TARGET = llml

ifeq	($(OS), Windows_NT)
		RM = del /Q
		FIX_PATH = $(subst /,\,$1)
		EXEC = $(TARGET).exe
else
		RM = rm -f
		FIX_PATH = $1
		EXEC = $(TARGET)
endif

SRC = src/llml.c
OBJ = $(SRC:.c=.o)

all: $(EXEC)

$(EXEC): $(OBJ)
				$(CC) $(OBJ) -o $(EXEC) -lm

%.o: %.c
				$(CC) $(CFLAGS) -c $< -o $@

clean:
				$(RM) $(call FIX_PATH,$(OBJ) $(EXEC))

.PHONY: all clean

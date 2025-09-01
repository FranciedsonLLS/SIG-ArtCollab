# NOTA: Makefile: compila todos os .c do src/ em um executável, usando include/ para os .h

CC = gcc
CFLAGS = -Wall -Iinclude
SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
TARGET = exec

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)


src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)

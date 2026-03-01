CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11 -pthread
TARGET = robot_simulator

SRC = src/main.c \
      src/buffer.c \
      src/control.c \
      src/scheduler.c \
      src/timing.c

all:
	$(CC) $(CFLAGS) $(SRC) -Iinclude -o $(TARGET)

clean:
	rm -f $(TARGET)

run: all
	sudo ./$(TARGET)

valgrind: all
	valgrind --leak-check=full ./$(TARGET)


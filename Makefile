TARGET = ./Bin/Program

CC = gcc
FLAGS = -Wall -Wextra -std=c90
SRCS = ./Src/Main.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET) clean

$(TARGET): $(OBJS)
	$(CC) $(FLAGS) -o $(TARGET) $(OBJS)

clean:
	$(RM) $(OBJS)
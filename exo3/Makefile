CC = gcc
CFLAGS = -Wall -Wextra -std=c99

TARGET = train_manager
SRCS = gestHorairesTrains.c main.c

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(TARGET)

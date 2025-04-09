CC = gcc
CFLAGS = -Wall -Wextra
SOURCES = main.c matrix.c
TARGET = lab1
all: $(TARGET)
$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)
clean:
	rm -f $(TARGET)
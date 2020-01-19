TARGET = prims.exe
HEADERS = graph.h
OBJECTS = prims.o graph.o

LIBS = -lm
CC = gcc
CFLAGS = -g -Wall

all: $(TARGET)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -Wall $(LIBS) -o $@

clean:
	-rm -f *.o
	-rm -f $(TARGET)

TARGET	= chess

CC		= gcc
CFLAGS 	= -O3 -c
LFLAGS	=
LIBS	= 

HEADERS	= $(wildcard src/*.h)
SRCS	= $(wildcard src/*.c)
OBJS	= $(patsubst src/%.c, bin/%.o, $(SRCS))

.PHONY: default all clean

default: $(TARGET)
all: default

%.o: $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) $< -o $@

$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(LFLAGS) $(LIBS) -o bin/$@

clean:
	rm -f bin/*.o
	rm -f bin/$(TARGET)

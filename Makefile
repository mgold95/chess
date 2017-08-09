TARGET	= chess

CC		= gcc
CFLAGS 	= -O3 -c
LFLAGS	=
LIBS	= 

HEADERS	= $(wildcard src/*.h)
OBJS	= $(patsubst src/%.c, bin/%.o, $(wildcard src/*.c))

.PHONY: default all clean Makefile

default: $(TARGET)
all: default
	echo $(OBJS)

bin/%.o: src/%.c $(HEADERS)
	$(CC) $(CFLAGS) $< -o $@

$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(LFLAGS) $(LIBS) -o bin/$@

clean:
	rm -f bin/*.o
	rm -f bin/$(TARGET)

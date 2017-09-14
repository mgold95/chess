TARGET	= chess

CC		= gcc
CFLAGS 	= -std=c11 -O3
LFLAGS	=
LIBS	= -lpthread

HEADERS	= $(wildcard src/*.h)
OBJS	= bin/game.o
OBJS	+= bin/types.o
OBJS	+= bin/uci.o

TESTHEADERS	= $(wildcard test/*.h)
TESTOBJS	= $(patsubst test/%.c, bin/test/%.o, $(wildcard test/*.c))

TESTCFLAGS	= -I./src/
TESTLFLAGS 	= -lcmocka
TESTTARGET	= run_tests

.PHONY: default all clean Makefile

default: $(TARGET)
all: default

outdir:
	@mkdir -p bin
	@mkdir -p bin/test

bin/%.o: src/%.c $(HEADERS) outdir
	$(CC) $(CFLAGS) -c $< -o $@

main: src/main.c $(HEADERS) outdir
	$(CC) $(CFLAGS) -c src/main.c -o bin/main.o

$(TARGET): $(OBJS) main
	$(CC) $(OBJS) bin/main.o $(LFLAGS) $(LIBS) -o bin/$@

test: $(TESTTARGET)

bin/test/%.o: test/%.c $(HEADERS) outdir
	$(CC) $(CFLAGS) $(TESTCFLAGS) -c $< -o $@

$(TESTTARGET): $(OBJS) $(TESTOBJS)
	$(CC) $(OBJS) $(TESTOBJS) $(LFLAGS) $(LIBS) $(TESTLFLAGS) -o bin/test/$@

clean:
	rm -f bin/*.o
	rm -f bin/$(TARGET)
	rm -rf bin/test

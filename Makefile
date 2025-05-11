CC=gcc
FLEX=flex
BISON=bison
TARGET=bin/compiler

all: $(TARGET)

$(TARGET): src/lexer.c src/parser.c src/main.c
	$(CC) -o $@ $^

src/lexer.c: src/lexer.l
	$(FLEX) -o src/lexer.c src/lexer.l

src/parser.c: src/parser.y
	$(BISON) -d -o src/parser.c src/parser.y

clean:
	rm -f src/*.c src/*.h $(TARGET)

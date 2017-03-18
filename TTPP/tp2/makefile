CFLAGS := -g -std=c99
CFLAGS +=  -Wall -Wformat=2 -Wshadow -Wpointer-arith -Wunreachable-code -Wconversion -Wno-sign-conversion -Wbad-function-cast -Werror

all: uniq-count comm heap-utils abb.o

run: all
	./comm nombres1.txt nombres2.txt

remove:
	rm *.o uniq-count comm heap-utils

include deps.mk

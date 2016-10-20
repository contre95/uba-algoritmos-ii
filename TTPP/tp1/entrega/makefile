CFLAGS := -g -std=c99 -Wall -Wformat=2
CFLAGS += -Wshadow -Wpointer-arith -Wunreachable-code
CFLAGS += -Wconversion -Wno-sign-conversion -Wbad-function-cast

all: paste more dc strutil.o test

remove:
	rm more paste dc test strutil.o dc.o test.o

include deps.mk

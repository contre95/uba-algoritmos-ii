CFLAGS := -g -std=c99 -Wall -Wformat=2
CFLAGS += -Wshadow -Wpointer-arith -Wunreachable-code
CFLAGS += -Wconversion -Wno-sign-conversion -Wbad-function-cast

all: paste more dc strutil.o test

remove:
	rm vgcore.* more paste dc test test.o

include deps_noenviar.mk

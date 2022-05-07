SRCS =  *.c
CFLAGS = -Wall -Werror -nostdlib -s -O3 -static
CC = gcc
PROG = runelf

all:
	${CC} ${CFLAGS} -o ${PROG} ${SRCS}

clean:
	rm $(PROG)

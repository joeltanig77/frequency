.SUFFIXES: .c .o
CC = gcc
CCFLAGS = -std=c99 -pedantic -Wall
EXEC = freq
OBJS = freq.o func.o

${EXEC}: ${OBJS}
	${CC} ${CCFLAGS} -o ${EXEC} ${OBJS}

.c.o:
	${CC} ${CCFLAGS} -c $<

run: ${EXEC}
	./${EXEC}

clean:
	rm -f ${EXEC} ${OBJS}

freq.o: freq.c func.h
func.o: func.c func.h

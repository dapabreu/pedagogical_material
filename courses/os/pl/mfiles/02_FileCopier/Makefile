CC = gcc
#compiler flags
FLAGS = -Wall
#linker flags ! check line 17
LDFLAGS = -lpthread -D_REENTRANT
OBJS = mycp_solved.o
PROG = mycp

###########

all: ${PROG}

clean:
	rm ${OBJS} ${PROG}

${PROG}:  ${OBJS}
	${CC} ${FLAGS} ${OBJS} -o $@ ${LDFLAGS}

.c.o:
	${CC} $< -c -o $@

###########
mycp.o: mycp_solved.c

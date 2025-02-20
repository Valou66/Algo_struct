CC=gcc
EXEC=td
CFLAGS=-Wall
SRC_DIR=./src/

all : TD_function.o main.o	
	${CC} ${CFLAGS} -o ${EXEC} TD_function.o main.o
	./$(EXEC)

TD_function.o : ${SRC_DIR}TD_function.c
	${CC} -c ${SRC_DIR}TD_function.c

main.o : ${SRC_DIR}main.c
	${CC} -c ${SRC_DIR}main.c




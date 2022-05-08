CC=g++
CFLAGS=-Wall -g
STD=c++17
FOLDER=./bin

all: folder client server clean

folder:
	mkdir -p ./${FOLDER}

client: 
	$(CC) -std=${STD} ${CFLAGS} -o ${FOLDER}/client runtime/client_runtime.cpp
server: 
	$(CC) -std=${STD} ${CFLAGS} -o ${FOLDER}/server runtime/server_runtime.cpp

.PHONY: clean
clean:
	rm -rf *.o && rm -r */**.dSYM
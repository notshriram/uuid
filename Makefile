CC=clang++
CFLAGS= -Wall -pedantic -std=c++20
SOURCES=./src/*.cpp
INCLUDES=./include

libuuid.a: uuid.o
	llvm-ar rcs libuuid.a uuid.o

uuid.o:
	$(CC) $(CFLAGS) -c -I$(INCLUDES) ./src/uuid.cpp -o uuid.o


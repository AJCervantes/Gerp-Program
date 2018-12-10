#
# Filename: gerp
# Contains: Makefile for project 2
# Andrew Cervantes
#
CC = clang++
CFLAGS = -Wall -Wextra -c -std=c++11 -O2
LDFLAGS = -g
gerp: main.o FSTreeTraversal.o Hash.o
	$(CC) -o gerp main.o FSTreeTraversal.o Hash.o FSTree.o DirNode.o

main.o: main.cpp FSTreeTraversal.h
FSTreeTraversal.o: FSTreeTraversal.cpp FSTreeTraversal.h Hash.h FSTree.h DirNode.h
Hash.o: Hash.cpp Hash.h NodeA.h 
clean:
	rm -f *.o core* *~ gerp

#Justin Gou
#jyg2qhc
#2/25/2020
#Makefile

CXX=clang++
CFLAGS=-Wall -O2
OBJECTS= BinaryNode.o BSTPathTest.o BinarySearchTree.o

a.out: $(OBJECTS)
	$(CXX) $(CFLAGS) $(OBJECTS)

BSTPathTest.o: BSTPathTest.cpp BinarySearchTree.h BinaryNode.h
BinaryNode.o: BinaryNode.cpp BinaryNode.h
BinarySearchTree.o: BinarySearchTree.cpp BinaryNode.h BinarySearchTree.h

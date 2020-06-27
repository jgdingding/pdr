#Justin Gou
#jyg2qhc
#2/26/2020
#Makefile

CXX=clang++
CFLAGS=-Wall -O2
OBJECTS= AVLNode.o AVLPathTest.o AVLTree.o

a.out: $(OBJECTS)
	$(CXX) $(CFLAGS) $(OBJECTS)

AVLNode.o: AVLNode.cpp AVLNode.h
AVLPathTest.o: AVLPathTest.cpp AVLTree.h AVLNode.h
AVLTree.o: AVLTree.cpp AVLNode.h AVLTree.h

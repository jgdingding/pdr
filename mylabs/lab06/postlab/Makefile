#Justin Gou
#jyg2qhc
#3/5/2020
#Makefile

CXX=clang++ $(CFLAGS)
CFLAGS=-Wall -O2
OBJECTS= hashTable.o timer.o wordPuzzle.o

a.out: $(OBJECTS)
	$(CXX) $(OBJECTS)

hashTable.o: hashTable.cpp hashTable.h
timer.o: timer.cpp timer.h
wordPuzzle.o: wordPuzzle.cpp timer.h hashTable.h

.PHONY: clean
clean:
	-rm -f *.o a.out

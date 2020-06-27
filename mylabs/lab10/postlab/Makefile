# Justin Gou
# jyg2qhc
# 4/13/2020
# Makefile

CXX = clang++
CFLAGS = -O2 -Wall

OFILES = huffmandec.o huffmannode.o

a.out: $(OFILES)
	$(CXX) $(CFLAGS) $(OFILES)

.PHONY:
	clean

clean:
	/bin/rm -f a.out *.o

# Justin Gou
# jyg2qhc
# 04/17/2020
# Makefile

CXX = clang++

CFLAGS = -O2 -Wall

a.out: topological.cpp Doxyfile
	$(CXX) $(CFLAGS) topological.cpp
	doxygen

.PHONY:
	clean

clean:
	/bin/rm -f *.o a.out

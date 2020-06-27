# Justin Gou
# jyg2qhc
# 04/20/2020
# Makefile

CXX = clang++

CFLAGS = -O2 -Wall

OFILES = traveling.o middleearth.o

a.out: $(OFILES) Doxyfile
	$(CXX) $(CFLAGS) $(OFILES)
	doxygen

.PHONY:
	clean

clean:
	/bin/rm -f *.o a.out

CC := gcc
CXX := g++
AR := ar -rcs
SO_LINK := -shared
CFLAGS := -D_FILE_OFFSET_BITS=64 -DSHMEM -fPIC -ggdb -O0

%.o : %.cpp
	$(CXX) -I. -c $(CFLAGS) $< -o $@

.PHONY: all

all: main libanimal.a libeagle.so libdog.so

libanimal.a: animal.o
	$(AR) $@ $^
	ranlib $@

libeagle.so: eagle.o libanimal.a
	$(CXX) $(SO_LINK) -I. -o $@ eagle.o -L. -lanimal

libdog.so: dog.o libanimal.a plugin.o
	$(CXX) $(SO_LINK) -I. -o $@ dog.o plugin.o -L. -lanimal

main: main.o libanimal.a plugin.o
	$(CXX) -I. -o $@ main.o plugin.o -L. -lanimal -ldl

clean:
	rm *.o *.a *.so main

CXX=~/bin/gcc62/bin/g++
DST=../../dst
OBJS=ai.o eval.o

all: $(OBJS)
	mv *.o $(DST)

%.o: %.cpp
	$(CXX) -c -O3 -o $*.o $*.cpp

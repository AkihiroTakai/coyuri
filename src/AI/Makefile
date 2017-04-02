CXX=g++
DST=../../dst
OBJS=ai.o eval.o

all: $(OBJS)
	mv *.o $(DST)

%.o: %.cpp
	$(CXX) -c -Ofast -march=native -std=c++14 -o $*.o $*.cpp

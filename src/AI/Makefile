CXX=icpc
DST=../../dst
OBJS=ai.o eval.o

all: $(OBJS)
	mv *.o $(DST)

%.o: %.cpp
	$(CXX) -c -fast -std=c++14 -o $*.o $*.cpp

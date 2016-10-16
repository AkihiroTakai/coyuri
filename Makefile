CXX=~/bin/gcc62/bin/g++
#CXX=g++
INCLUDE=./include
DST=./dst
SRC=./src
BIN=./bin
CFLAGS=`fltk-config --cxxflags`
LDFLAGS=`fltk-config --ldflags --use-images`
OBJS = $(DST)/point.o $(DST)/main.o

coyuri: $(OBJS)
	$(CXX) -o $(BIN)/coyuri  dst/main.o dst/point.o $(LDFLAGS)

$(DST)/%.o: $(SRC)/%.cpp
	$(CXX) $(CFLAGS) -c -o $(DST)/$*.o $(SRC)/$*.cpp $(LDFLAGS)

clean:
	rm $(DST)/*.o $(BIN)/coyuri

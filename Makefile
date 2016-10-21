CXX=~/bin/gcc62/bin/g++
#CXX=g++
INCLUDE=./include
DST=./dst
SRC=./src
BIN=./bin
CFLAGS=`fltk-config --cxxflags`
LDFLAGS=`fltk-config --ldflags --use-images`
OBJS = $(DST)/point.o $(DST)/main.o $(DST)/init.o $(DST)/koma.o $(DST)/wcm.o $(DST)/masu.o $(DST)/move.o

coyuri: $(OBJS)
	$(CXX) -o $(BIN)/coyuri  $(OBJS) $(LDFLAGS)

$(DST)/%.o: $(SRC)/%.cpp
	$(CXX) $(CFLAGS) -c -o $(DST)/$*.o $(SRC)/$*.cpp $(LDFLAGS)

clean:
	rm $(DST)/*.o $(BIN)/coyuri

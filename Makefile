CXX=~/bin/gcc62/bin/g++
INCLUDE=./include
DST=./dst
SRC=./src
BIN=./bin
CFLAGS=`fltk-config --cxxflags`
LDFLAGS=`fltk-config --ldflags --use-images`
OBJS=$(DST)/main.o

coyuri: $(OBJS)
	$(CXX) $(CFLAGS) -o $(BIN)/coyuri  $(DST)/*.o $(LDFLAGS) 

$(DST)/%.o: $(SRC)/%.cpp
	$(CXX) $(CFLAGS) -c -o $(DST)/$*.o $(SRC)/$*.cpp $(LDFLAGS) -I$(INCLUDE)

clean:
	rm $(dst)/*.o $(BIN)/coyuri

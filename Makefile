#CXX=~/bin/gcc62/bin/g++
CXX=g++
INCLUDE=./include
DST=./dst
SRC=./src
BIN=./bin
AI=$(SRC)/AI
CFLAGS=`fltk-config --cxxflags`
LDFLAGS=`fltk-config --ldflags --use-images`
OBJS = $(DST)/point.o $(DST)/main.o $(DST)/init.o $(DST)/koma.o $(DST)/wcm.o $(DST)/masu.o $(DST)/move.o $(DST)/draw.o \
 $(DST)/banmen.o $(DST)/tegoma.o $(DST)/naru.o $(DST)/file.o

coyuri: $(OBJS)
	mkdir -p bin
	cd $(AI) && make all
	$(CXX) -o $(BIN)/coyuri  $(OBJS) $(DST)/ai.o $(DST)/eval.o $(LDFLAGS)

$(DST)/%.o: $(SRC)/%.cpp
	mkdir -p dst
	$(CXX) $(CFLAGS) -Ofast -march=native -std=c++14 -c -o $(DST)/$*.o $(SRC)/$*.cpp $(LDFLAGS)


clean:
	rm -f $(DST)/*.o $(BIN)/coyuri


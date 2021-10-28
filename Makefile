CXX=g++
CXXFLAGS=-O2 -std=c++17
LDFLAGS=$(CXXFLAGS)
EXE=solver
OBJS=src/main.o

default: $(EXE)

$(EXE): $(OBJS)
	$(CXX) $(LDFLAGS) -o $(EXE) $^ 

test: $(EXE) test/test.cpp
	$(CXX) $(CXXFLAGS) -o test/tester test/test.cpp
	./test/tester

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f src/*.o $(EXE) test/tester

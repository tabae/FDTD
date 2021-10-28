CXX=g++
CXXFLAGS=-O2 -std=c++17
LDFLAGS=$(CXXFLAGS)
EXE=solver
OBJS=src/main.o
HEADERS=src/absorbing_boundary_condition.hpp \
	src/color.hpp \
	src/config.hpp \
	src/e_field.hpp \
	src/field.hpp \
	src/h_field.hpp \
	src/output.hpp \
	src/setup.hpp

default: $(EXE)

$(EXE): $(OBJS) $(HEADERS)
	$(CXX) $(LDFLAGS) -o $(EXE) $(OBJS) 

test: $(EXE) test/test.cpp
	$(CXX) $(CXXFLAGS) -o test/tester test/test.cpp
	./test/tester

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f src/*.o $(EXE) test/tester

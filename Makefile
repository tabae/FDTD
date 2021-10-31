CXX=g++
CXXFLAGS=-O2 -std=c++17
LDFLAGS=$(CXXFLAGS)
EXE=solver
SRC=src/main.cpp
HEADERS=src/absorbing_boundary_condition.hpp \
	src/color.hpp \
	src/config.hpp \
	src/e_field.hpp \
	src/field.hpp \
	src/h_field.hpp \
	src/log.hpp \
	src/medium.hpp \
	src/output.hpp \
	src/physical_constants.hpp \
	src/setup.hpp

default: $(EXE)

$(EXE): $(SRC) $(HEADERS)
	$(CXX) $(LDFLAGS) -o $(EXE) $(SRC) 

test: $(EXE) test/test.cpp
	$(CXX) $(CXXFLAGS) -o test/tester test/test.cpp
	./test/tester

clean:
	rm -f src/*.o $(EXE) test/tester

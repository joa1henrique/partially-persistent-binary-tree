CXX = g++
CXXFLAGS = -std=c++11 -Wall

all: build

build: main.cpp bst.cpp bst.hpp
	$(CXX) $(CXXFLAGS) -o bst_persistente main.cpp bst.cpp

run: build
	./bst_persistente $(ARGS)

clean:
	rm -f bst_persistente

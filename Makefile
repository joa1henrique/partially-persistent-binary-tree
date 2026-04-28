CXX = g++
CXXFLAGS = -std=c++11 -Wall

all: build

build: main.cpp
	$(CXX) $(CXXFLAGS) -o bst_persistente main.cpp

run: build
	./bst_persistente $(ARGS)

clean:
	rm -f bst_persistente

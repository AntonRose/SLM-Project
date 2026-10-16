CXX      = g++
CXXFLAGS = -std=c++17 -O2 -Wall -Wextra
SRC      = src

slm: main.o read.o model.o
	$(CXX) $(CXXFLAGS) -o slm main.o read.o model.o

main.o: $(SRC)/main.cpp $(SRC)/read.h $(SRC)/model.h
	$(CXX) $(CXXFLAGS) -c $(SRC)/main.cpp

read.o: $(SRC)/read.cpp $(SRC)/read.h
	$(CXX) $(CXXFLAGS) -c $(SRC)/read.cpp

model.o: $(SRC)/model.cpp $(SRC)/model.h
	$(CXX) $(CXXFLAGS) -c $(SRC)/model.cpp

clean:
	rm -f slm *.o

.PHONY: clean

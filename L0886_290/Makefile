CXX = g++
CXXFLAGS = -std=c++11 -Wall
TARGET = L0886_290
OBJ = L0886_290.o L0886_290test.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

L0886_290.o: L0886_290.cpp L0886_290.hpp
	$(CXX) $(CXXFLAGS) -c L0886_290.cpp

L0886_290test.o: L0886_290test.cpp L0886_290.hpp
	$(CXX) $(CXXFLAGS) -c L0886_290test.cpp

clean:
	rm -f *.o $(TARGET)
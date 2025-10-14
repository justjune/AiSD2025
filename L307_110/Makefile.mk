CXX = g++


CXXFLAGS = -Wall -std=c++11


ifeq ($(OS),Windows_NT)
	RM = del /Q
	TARGET = tree_app.exe 
else
	RM = rm -f 
	TARGET = tree_app 
endif


SRCS = L307_110test.cpp

OBJECTS = $(SRCS:.cpp=.o)


all: $(TARGET)


$(TARGET): $(OBJECTS)

	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)


%.o: %.cpp

	$(CXX) $(CXXFLAGS) -c $< -o $@


clean:

	$(RM) $(OBJECTS) $(TARGET)


.PHONY: all clean
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
TARGET_MAIN = main
TARGET_TESTS = tests
SOURCES_MAIN = main.cpp
SOURCES_TESTS = tests.cpp
HEADERS = my_qsort.hpp

all: $(TARGET_MAIN) $(TARGET_TESTS)

$(TARGET_MAIN): $(SOURCES_MAIN) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $(TARGET_MAIN) $(SOURCES_MAIN)

$(TARGET_TESTS): $(SOURCES_TESTS) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $(TARGET_TESTS) $(SOURCES_TESTS)

run_main: $(TARGET_MAIN)
	./$(TARGET_MAIN)

run_tests: $(TARGET_TESTS)
	./$(TARGET_TESTS)

clean:
	rm -f $(TARGET_MAIN) $(TARGET_TESTS)

.PHONY: all run_main run_tests clean

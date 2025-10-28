ifeq ($(OS),Windows_NT)
	RM=del
	EXT=.exe
else
	RM=rm
	EXT=

endif


l0701241o=L0701_241.o L0701_241_test.o
L0701241.exe: $(l0701241o)
	$(CXX) -o L0701241.exe $(l0701241o)

L0701_241.o: L0701_241.cpp
	$(CXX) -c L0701_241.cpp

L0701_241_test.o: L0701_241_test.cpp L0701_241.hpp
	$(CXX) -c L0701_241_test.cpp

.PHONY: clean
clean:
	$(RM) $(objects) $(l0701241o) m.exe L0701241.exe

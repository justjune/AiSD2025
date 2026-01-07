
l303088o=L303_088.o L303_088test.o
L303088.exe: $(l303088o)
	$(CXX) -o L303088.exe $(l303088o)

L303_088.o: L303_088.cpp
	$(CXX) -c L303_088.cpp

L303_088test.o: L303_088test.cpp L303_088.hpp
	$(CXX) -c L303_088test.cpp

.PHONY: clean run all
clean:
	$(RM) $(objects) $(l303088o) m.exe L303088.exe
run:
	L303088.exe
all: L303088.exe run clean


l101022o=L101_022.o L101_022test.o
L101022.exe: $(l101022o)
	$(CXX) -o L101022.exe $(l101022o)

L101_022.o: L101_022.c
	$(CXX) -c L101_022.c

L101_022test.o: L101_022test.c L101_022.h
	$(CXX) -c L101_022test.c

.PHONY: clean run all
clean:
	$(RM) $(objects) $(l101022o) m.exe L101022.exe
run:
	L101022.exe
all: L101022.exe run clean
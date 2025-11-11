CXX = g++

l025077o = L025_077.o L025_077test.o

L025_077.exe: $(l025077o)
	$(CXX) -o L025_077.exe $(l025077o)

L025_077.o: L025_077.cpp L025_077.hpp
	$(CXX) -c L025_077.cpp

L025_077test.o: L025_077test.cpp L025_077.hpp
	$(CXX) -c L025_077test.cpp

.PHONY: clean
clean:
	rm -f $(l025077o) L025_077.exe
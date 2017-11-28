CXX = g++


all: 
	$(CXX) argumentretval.cpp  -o argumentretval
	$(CXX) heapalloc.cpp  -o heapalloc
	$(CXX) stackalloc.cpp  -o stackalloc
	$(CXX) operatoroverride.cpp -o operatoroverride
	$(CXX) vt.cpp -o vt
	$(CXX) multivt.cpp -o multivt

dbg: 
	$(CXX) -g argumentretval.cpp  -o argumentretval 
	$(CXX) -g heapalloc.cpp  -o heapalloc 
	$(CXX) -g stackalloc.cpp  -o stackalloc 
	$(CXX) -g operatoroverride.cpp -o operatoroverride 
	$(CXX) -g vt.cpp -o vt
	$(CXX) -g multivt.cpp -o multivt

sec: 
	$(CXX) -g -fsanitize=address argumentretval.cpp  -o argumentretval 
	$(CXX) -g -fsanitize=address heapalloc.cpp  -o heapalloc 
	$(CXX) -g -fsanitize=address stackalloc.cpp  -o stackalloc 
	$(CXX) -g -fsanitize=address operatoroverride.cpp -o operatoroverride 
	$(CXX) -g -fsanitize=address vt.cpp -o vt
	$(CXX) -g -fsanitize=address multivt.cpp -o multivt

clean:
	rm stackalloc heapalloc argumentretval operatoroverride vt multivt

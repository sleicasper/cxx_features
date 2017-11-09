CXX = g++


all: 
	$(CXX) argumentretval.cpp  -o argumentretval
	$(CXX) heapalloc.cpp  -o heapalloc
	$(CXX) stackalloc.cpp  -o stackalloc
	$(CXX) operatoroverride.cpp -o operatoroverride

dbg: 
	$(CXX) -fsanitize=address argumentretval.cpp  -o argumentretval 
	$(CXX) -fsanitize=address heapalloc.cpp  -o heapalloc 
	$(CXX) -fsanitize=address stackalloc.cpp  -o stackalloc 
	$(CXX) -fsanitize=address operatoroverride.cpp -o operatoroverride 

clean:
	rm stackalloc heapalloc argumentretval operatoroverride

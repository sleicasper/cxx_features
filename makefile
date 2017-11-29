CXX = g++


testobjs = \
	argumentret \
	heapalloc \
	stackalloc \
	operatoroverride \
	vt \
	constructor \
	rvalue \
	multivt 


all:
	@for target in $(testobjs); 	\
	do				\
		$(CXX) -std=c++11 -fno-elide-constructors -o $$target $$target.cpp;	\
	done

dbg:
	@for target in $(testobjs); 	\
	do				\
		$(CXX) -g -o $$target $$target.cpp;	\
	done

sec:
	@for target in $(testobjs); 	\
	do				\
		$(CXX) -g -fsanitize=address -o $$target $$target.cpp;	\
	done



clean:
	rm $(testobjs)

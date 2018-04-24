CXX = g++


testobjs = \
	argumentret \
	heapalloc \
	stackalloc \
	operatoroverride \
	vt \
	constructor \
	rvalue \
	nonameobj \
	newobjectinargument \
	multivt 


all:
	@for target in $(testobjs); 	\
	do				\
		$(CXX) -std=c++11 -fno-elide-constructors -o $$target $$target.cpp;	\
	done

dbg:
	@for target in $(testobjs); 	\
	do				\
		$(CXX) -std=c++11 -g -o $$target $$target.cpp;	\
	done

sec:
	@for target in $(testobjs); 	\
	do				\
		$(CXX) -std=c++11 -g -fsanitize=address -o $$target $$target.cpp;	\
	done



clean:
	rm $(testobjs)

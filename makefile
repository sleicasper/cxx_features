CXX = g++


testobjs = \
	argumentretval \
	argumentretval \
	heapalloc \
	stackalloc \
	operatoroverride \
	vt \
	constructor \
	multivt 


all:
	@for target in $(testobjs); 	\
	do				\
		$(CXX) -o $$target $$target.cpp;	\
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

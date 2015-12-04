include /home/cadangelo/opt/moab/lib/moab.make


CXXFLAGS += -Wall -pipe -pedantic -Wno-long-long -Wextra -Wcast-align  -Wpointer-arith -Wformat -Wformat-security -Wshadow -Wunused-parameter -Wno-variadic-macros -O2 -DNDEBUG ${MOAB_INCLUDES} ${MOAB_CPPFLAGS} -g
#MOAB_LIBS_LINK = ${MOAB_LDFLAGS} -L${MOAB_LIBDIR} -lMOAB -lhdf5 -lpthread -lz -ldl -lm -lpthread -lz -ldl -lm
CXX = mpic++

all: test

test.o: test.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

test: test.o
	$(CXX) $(CXXFLAGS) $^ $(MOAB_LIBS_LINK) -o $@

clean: 
	rm -f *.o test

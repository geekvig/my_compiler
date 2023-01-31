OBJECTS= ./build/compiler.o ./build/cprocess.o
INCLUDES= -I./
all: ${OBJECTS}
	g++ main.cpp ${INCLUDES} ${OBJECTS} -g -o ./main

./build/compiler.o: ./compiler.cpp
	g++ ./compiler.cpp ${INCLUDES} -o ./build/compiler.o -g -c

./build/cprocess.o: ./cprocess.cpp
	g++ ./cprocess.cpp ${INCLUDES} -o ./build/cprocess.o -g -c

clean:
	rm ./main
	rm -rf ${OBJECTS}
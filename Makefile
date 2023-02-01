OBJECTS= ./build/compiler.o ./build/compile_process.o ./build/lexer.o ./build/lex_process.o ./build/lex_functions.o
INCLUDES= -I./
all: ${OBJECTS}
	g++ main.cpp ${INCLUDES} ${OBJECTS} -g -o ./main

./build/compiler.o: ./compiler.cpp
	g++ ./compiler.cpp ${INCLUDES} -o ./build/compiler.o -g -c

./build/compile_process.o: ./compile_process.cpp
	g++ ./compile_process.cpp ${INCLUDES} -o ./build/compile_process.o -g -c

./build/lexer.o: ./lexer.cpp
	g++ ./lexer.cpp ${INCLUDES} -o ./build/lexer.o -g -c

./build/lex_process.o: ./lex_process.cpp
	g++ ./lex_process.cpp ${INCLUDES} -o ./build/lex_process.o -g -c

./build/lex_functions.o: ./lex_functions.cpp
	g++ ./lex_functions.cpp ${INCLUDES} -o ./build/lex_functions.o -g -c

clean:
	rm ./main
	rm -rf ${OBJECTS}
F= -std=c++11 -ggdb
P= string_test standard_main

all: $P

string_test:Alloc.h Alloc.cpp String.h String.cpp string_test.cpp
	g++ $F String.cpp Alloc.cpp string_test.cpp -o string_test

standard_main: standard_main.cpp String.h
	g++ $F standard_main.cpp -o standard_main

clean:
	/bin/rm -f $P

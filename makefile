all: bsts.exe

bsts.exe: bst.o  bstTester.o
	g++ bst.o  bstTester.o  -o bsts.exe
	
bstTester: bstTester.cpp bst.h
	g++ -c bstTester.cpp
	
bst.o: bst.cpp bst.h
	g++ -c bst.cpp
	
clean: 
	rm *.o bsts.exe

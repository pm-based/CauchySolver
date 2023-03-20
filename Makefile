
CNSolver:
	g++ -c -std=c++20 -I/home/p2/PACS/pacs-examples/Examples/src/Utilities CNSolver.cpp -o CNSolver.o
	
main: 
	g++ -c -std=c++20 -I/home/p2/PACS/pacs-examples/Examples/src/Utilities main.cpp -o main.o
	
compile:
	g++ -std=c++20 -I/home/p2/PACS/pacs-examples/Examples/src/Utilities CNSolver.o main.o -o main


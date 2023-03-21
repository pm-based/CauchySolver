
CNSolver:
	g++ -c -std=c++20 -I/home/p2/PACS/pacs-examples/Examples/src/Utilities CNSolver.cpp -o CNSolver.o
	
main: 
	g++ -c -std=c++20 -I/home/p2/PACS/pacs-examples/Examples/src/Utilities main.cpp -I$(mkBoostInc) -o main.o
	
compile:
	g++ -std=c++20 -L$(mkBoostLib) -lboost_iostreams -lboost_system -lboost_filesystem -I/home/p2/PACS/pacs-examples/Examples/src/Utilities CNSolver.o main.o -o main

testCN:
	g++ -std=c++20 -I/home/p2/PACS/pacs-examples/Examples/src/Utilities testCN.cpp -o testCN

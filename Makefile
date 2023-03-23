
CNSolver:
	g++ -c -std=c++20 -I/home/p2/PACS/pacs-examples/Examples/src/Utilities CNSolver.cpp -o CNSolver.o
	
main: 
	g++ -c -std=c++20 -I/home/p2/PACS/pacs-examples/Examples/src/Utilities -I$(mkBoostInc) main.cpp -o main.o
	
compile:
	g++ -std=c++20 -L$(mkBoostLib) -lboost_iostreams -lboost_system -lboost_filesystem -I/home/p2/PACS/pacs-examples/Examples/src/Utilities CNSolver.o cauchyProblem.o main.o -o main

testCN:
	g++ -std=c++20 -I/home/p2/PACS/pacs-examples/Examples/src/Utilities testCNSolver.cpp -o testCN

cauchy:
	g++ -c -std=c++20 -I/home/p2/PACS/pacs-examples/Examples/src/Utilities -I$(mkBoostInc) cauchyProblem.cpp -o cauchyProblem.o

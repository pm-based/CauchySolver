PATH_PACSEXAMPLES = /home/p2/PACS

CXXFLAGS = -std=c++20
CPPFLAGS = -I$(PATH_PACSEXAMPLES)/pacs-examples/Examples/src/Utilities -I$(PATH_PACSEXAMPLES)/pacs-examples/Examples/src/LinearAlgebraUtil -I$(mkBoostInc)
LIBS = -lboost_iostreams -lboost_system -lboost_filesystem
LDFLAGS = -L$(mkBoostLib)


all: main

main: Solver.o cauchyProblem.o main.o
	$(CXX) $(LDFLAGS) $(LIBS) Solver.o cauchyProblem.o main.o -o main

cauchyProblem.o:
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c cauchyProblem.cpp -o cauchyProblem.o
	
Solver.o:
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c Solver.cpp -o Solver.o

main.o:
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c main.cpp -o main.o

clean:
	$(RM) *.o 

distclean: clean
	$(RM) main Solution.txt

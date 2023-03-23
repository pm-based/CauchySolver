#include <iostream>
#include "cauchyProblem.hpp"
#include "CNSolver.hpp"
#include "gnuplot-iostream.hpp" // interface with gnuplot

using NumSolution = std::tuple<std::vector<double>, std::vector<double>>;

NumSolution CauchyProblem::CNSolution(){
	if (ComputedCN == false) { //Avoid multiple computetion
		CNSol = CNSolver(odefun, InitialValue, InitialTime, EndTime, Nsteps);
	};

	return(CNSol);
}

void CauchyProblem::plot(){
	if (ComputedCN == false){CNSolution();};
	
	Gnuplot gp; // gnuplot iostream
	gp << "plot" << gp.file1d(CNSol) << std::endl;
	return;
}

void CauchyProblem::print(){
	if (ComputedCN == false){CNSolution();};
	
	for(int i = 0; i <= Nsteps; i++){
		std::cout<<"u(" << std::get<0>(CNSol)[i] << ") =" <<
		 std::get<1>(CNSol)[i] << std::endl;
	};
	return;
}

void CauchyProblem::save(){
	std::cout << "Saving solution..." << std::endl;
	std::ofstream file("Solution.txt");
	file << "solution of the cauchy problem: " << std::endl;
	for(int i = 0; i <= Nsteps; i++){
		file<<"u(" << std::get<0>(CNSol)[i] << ") = " <<
		 std::get<1>(CNSol)[i] << std::endl;
	};
	std::cout << "Solution saved in Solution.txt" << std::endl;
	return;
}

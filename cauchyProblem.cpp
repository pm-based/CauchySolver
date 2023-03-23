#include "cauchyProblem.hpp"
#include "CNSolver.hpp"
#include "gnuplot-iostream.hpp" // interface with gnuplot

using NumSolution = std::tuple<std::vector<double>, std::vector<double>>;

NumSolution CauchyProblem::CNSolution(){
	if (ComputedCN == false) { //Avoid multiple computetion
		CNSol = CNSolver(odefun, InitialValue, InitialTime, EndTime, Nsteps);};

	return(CNSol);
}

void CauchyProblem::plot(){
	Gnuplot gp; // gnuplot iostream
	gp << "plot" << gp.file1d(CNSol) << std::endl;
	return;
}

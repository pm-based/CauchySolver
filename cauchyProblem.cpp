#include "cauchyProblem.hpp"
#include "CNSolver.hpp"

using NumSolution = std::tuple<std::vector<double>, std::vector<double>>;

NumSolution CauchyProblem::CNSolution(){
	if (ComputedCN == false) { //Avoid multiple computetion
		CNSol = CNSolver(odefun, InitialValue, InitialTime, EndTime, Nsteps);};

	return(CNSol);
}

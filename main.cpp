#include <iostream>
#include "CNSolver.hpp"
#include "gnuplot-iostream.hpp" // interface with gnuplot
#include "cauchyProblem.hpp"

int main(){
	std::function<double(double,double)> fun = [](double t, double y){return -t*exp(-y);};
	//std::function<double(double,double)> fun = [](double t, double y){return 4*y;};
	double y0 = 0;
	int N = 100;
	double T = 1;
	auto p = CNSolver(fun, y0, T, N);
	
	CauchyProblem ChallengeProblem(fun);
	
	Gnuplot gp; // gnuplot iostream
	gp << "plot" << gp.file1d(ChallengeProblem.CNSolution()) << std::endl;

	return(0);
}



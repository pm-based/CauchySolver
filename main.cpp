#include <iostream>
#include "CNSolver.hpp"
#include "gnuplot-iostream.hpp" // interface with gnuplot

int main(){
	std::function<double(double,double)> fun = [](double t, double y){return -t*exp(-y);};
	//std::function<double(double,double)> fun = [](double t, double y){return 4*y;};
	double y0 = 0;
	int N = 100;
	double T = 1;
	auto p = CNSolver(fun, y0, T, N);

	Gnuplot gp; // gnuplot iostream
	gp << "plot" << gp.file1d(p) << std::endl;

	return(0);
}



#include <iostream>
#include "CNSolver.hpp"
//#include <functional>
//#include <numbers>

int main(){
	std::function<double(double,double)> fun = [](double t, double y){return -t*exp(-y);};
	double y0 = 0;
	int N = 100;
	double T = 1;
	auto p = CNSolver(fun, y0, T, N);


}

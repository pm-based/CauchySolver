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
	auto max_u = std::max_element(std::get<1>(p).begin(),std::get<1>(p).end());
	auto max_t = std::max_element(std::get<0>(p).begin(),std::get<0>(p).end());

	std::cout<<*max_u<<std::endl;
	std::cout<<*max_t<<std::endl;
	
	return(0);
}

#include <functional>
#include "/home/p2/PACS/pacs-examples/Examples/src/LinearAlgebraUtil/basicZeroFun.hpp"
#include <vector>
#include <iostream>

int main(){
	const std::function<double(double,double)> odefun = [](double t, double y){
		return(-t*exp(-y));
	};
	const double y0 = 2;
	const double T = 5;
	const int N = 1000;
	
	const double h = T/N;
	std::vector<double> u(N+1);
	std::vector<double> t(N+1);
	t[0] = 0;
	u[0] = y0;
	
	for(int i = 1; i <= N; i++){	
		t[i] = i*h;
		
		const std::function<double(double)> F = [&odefun,h,&t,&u,i](double x) {
			return(x -(h/2.)*( odefun(t[i],x) + odefun(t[i-1],u[i-1]) ) 					-u[i-1]);
		};
		u[i] = std::get<0>(apsc::secant(F, -5, 5));
	}
	
	//to print the result
	for(int i = 0; i <= N; i++){
		std::cout<<"u(" <<t[i] << ") = " <<u[i]<<std::endl;
	}

	return(0);
}


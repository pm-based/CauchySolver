#include "CNSolver.hpp"

using ODE = std::function<double(double,double)>;
using NumSolution = std::tuple<std::vector<double>, std::vector<double>>;
using Fun = std::function<double(double)>;

NumSolution CNSolver(const ODE & odefun, const double & y0, const double & t0, const double & T, const int & N){
	const double h = (T-t0)/N;
	std::vector<double> u(N+1);
	std::vector<double> t(N+1);
	t[0] = t0;
	u[0] = y0;
	
	//const Fun F_t = [&odefun,h,&t,&u](int i, double x) {
	//	return(x -(h/2.)*( odefun(t[i],x) + odefun(t[i-1],u[i-1]) )-u[i-1]);};
	
	for(int i = 1; i <= N; i++){	
		t[i] = t[i-1] + h;
		
		//const Fun F = [&F_t,i](double x) {return(F_t(i,x));};
		
		const Fun F = [&odefun,h,&t,&u,i](double x) {
			return(x -(h/2.)*( odefun(t[i],x) + odefun(t[i-1],u[i-1]) ) 					-u[i-1]);
			};
		u[i] = std::get<0>(apsc::secant(F, u[i-1]-2*odefun(t[i],u[i-1]), u[i-1]+2*odefun(t[i],u[i-1])));
	//	u[i] = std::get<0>(apsc::secant(F, -5, 5));
	}
	
	return{std::make_tuple(t,u)};
}


#include "Solver.hpp"

using ODE = std::function<double(double,double)>;
using NumSolution = std::tuple<std::vector<double>, std::vector<double>>;
using Fun = std::function<double(double)>;

NumSolution Solver(const ODE & odefun, const double & y0, const double & t0, const double & T, const int & N, const double & theta){
	const double ThetaA = 1-theta; // to implement the general theta method
	const double h = (T-t0)/N; 	// Time step
	std::vector<double> u(N+1);	// Vector of the solution
	std::vector<double> t(N+1);	// Vector of the time
	t[0] = t0;	// Inital time
	u[0] = y0;	// Initial value
	
	//const Fun F_t = [&odefun,h,&t,&u](int i, double x) {
	//	return(x -(h/2.)*( odefun(t[i],x) + odefun(t[i-1],u[i-1]) )-u[i-1]);};
	
	for(int i = 1; i <= N; i++){	
		t[i] = t[i-1] + h;
		
		const Fun F = [&odefun,h,&t,&u,i,theta,ThetaA](double x) {
			return(x -h*(theta*odefun(t[i],x) + ThetaA*odefun(t[i-1],u[i-1]))-u[i-1]);
			};
		
		// The two points of the secant are choosen in according with the derivative and adding some "extra margin" near the last value
		u[i] = std::get<0>(apsc::secant(F, u[i-1]-2*odefun(t[i],u[i-1]-0.01), u[i-1]+2*odefun(t[i],u[i-1])+0.01));
	}
	
	return{std::make_tuple(t,u)};
}


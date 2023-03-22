#include "CNSolver.hpp"


std::tuple<std::vector<double>, std::vector<double>> CNSolver(const std::function<double(double,double)>& odefun, const double & y0, const double & T, const int & N){
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
	
	return{std::make_tuple(t,u)};
}


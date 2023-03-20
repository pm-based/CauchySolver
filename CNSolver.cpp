#include "CNSolver.hpp"


std::tuple<std::vector<double>, std::vector<double>> CNSolver(const std::function<double(double,double)>& f, const double & y0, const double & T, const int & N){
	const double h = T/N;
	std::vector<double> u(N+1);
	std::vector<double> t(N+1);
	u[0] = y0;
	t[0] = 0;
	for(auto i=0; i <= N; i++){
		double t_i = h*i;
		t.push_back(t_i);
		u.push_back(apsc::bisection([&f,h,t_i](double x) {return (x-(h/2.)*(f(t_i+h,x)+f(t_i,x)));}, 0, T));

	}
	return{std::make_tuple(t,u)};
}


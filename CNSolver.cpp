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
		double u_i;
		std::tie(u_i, std::ignore) = apsc::secant([&f,h,t_i](double x) {return (x-(h/2.)*(f(t_i+h,x)+f(t_i,x)));}, 0, T);
		u.push_back(u_i);

	}
	return{std::make_tuple(t,u)};
}


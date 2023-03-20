#include "CNSolver.hpp"


std::tuple<std::vector<double>, std::vector<double>> CNSolver(const std::function<double(double,double)>& f, const double & y0, const double & T, const int & N){
	const double h = T/N;
	std::vector<double> u(N+1);
	std::vector<double> t(N+1);
	static double u_i = y0;
	double t_i = 0;
	u[0] = u_i;
	t[0] = t_i;
	for(auto i=1; i <= N; i++){
		t_i = h*i; // i=1 then t_i = h. i=N then t_i = T
		t.push_back(t_i);
		double u_i = std::get<0>(apsc::secant([&f,h,t_i,u_i](double x) {return(x-(h/2.)*(f(t_i,x)+f(t_i-h,u_i)-u_i));}, 0, T));
		//u.push_back(u_i);
		u[i] = u_i;
		std::cout<<"t: " << t_i << "\t u: " << u_i << std::endl;
	
	}
	return{std::make_tuple(t,u)};
}


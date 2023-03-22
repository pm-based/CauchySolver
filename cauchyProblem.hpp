#include <tuple>
#include <vector>
#include <functional>

class CauchyProblem {
	using ODE = std::function<double(double,double)>;
	using NumSolution = std::tuple<std::vector<double>, std::vector<double>>;
	
	public:
		CauchyProblem(ODE f, double y0, double t0, double t1, int N):
			odefun(f),
			InitialValue(y0),
			InitialTime(t0),
			EndTime(t1),
			Nsteps(N)
			{};
		CauchyProblem(ODE f): odefun(f) {};
			
		NumSolution CNSolution();
		
	private:
		// definition of the cauchy problem
		const ODE odefun; 
		const double InitialValue = 0;
		const double InitialTime = 0;
		const double EndTime = 1;
		
		// definition of solvig parameter
		const int Nsteps = 100;	//Number of steps
		
		// Solution
		NumSolution sol;
		

};

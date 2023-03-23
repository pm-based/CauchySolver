#include <tuple>
#include <vector>
#include <functional>

using ODE = std::function<double(double,double)>;
using NumSolution = std::tuple<std::vector<double>, std::vector<double>>;


//Class that define a Cauchy problem, and implement the methods to get the solution
class CauchyProblem {	
	public:
		//complete constructor: full definition of a cauchy problem
		CauchyProblem(ODE f, double y0, double t0, double t1):
			odefun(f),
			InitialValue(y0),
			InitialTime(t0),
			EndTime(t1)
			{};
		
		//constructor only with the specified ode function
		CauchyProblem(ODE f): odefun(f) {};
		
		//method returning the Crank-Nicolson solution of the problem.
		//it return a NumSolution type aka tuple of two vector, 
		//the first with the time steps and the second with the corrisponding value of the solution
		NumSolution CNSolution();
		
		//method to set a costumize number of steps
		void SetNumberOfSteps(const int & N){Nsteps = N;};
		
		//method to plot the solution
		void plot();
		
		//method to print the solution
		void print();
		
		//method to save the solution in a file
		void save();
		
	private:
		// definition of the cauchy problem. They are private since characterize
		//the cauchy problem. If they could be changed then it would be a different cauchy problem.
		const ODE odefun; 
		const double InitialValue = 0;
		const double InitialTime = 0;
		const double EndTime = 1;
		
		// definition of solvig parameter
		int Nsteps = 100;	//Number of steps
		
		
		// to avoid multiple computation of the solution an istance of the class
		// save the value and return it if it is already computed.
		bool ComputedCN = 0; //Indicate if the CN solution has already been computed
		
		// Solutions
		NumSolution CNSol;
		

};

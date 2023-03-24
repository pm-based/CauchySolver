#include <tuple>
#include <vector>
#include <functional>
#include <array>
#include <iostream>
#include "Solver.hpp"
#include "gnuplot-iostream.hpp" // interface with gnuplot

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
		
		//methods returning the solutions of the problem.
		//they return a NumSolution type aka tuple of two vector, 
		//the first with the time steps and the second with the corrisponding value of the solution
		//All those methods call the private method CallSolver(const int)
		//in order to compute the solution with the specified theta		
		NumSolution ThetaSolution(const double & theta); //generic theta
		NumSolution EFSolution() {return(CallSolver(1));}; //Euler Forward 
		NumSolution EBSolution() {return(CallSolver(2));}; //Euler Backward
		NumSolution CNSolution() {return(CallSolver(3));}; //Crank-Nicolson
		
		//method to set a costumize number of steps
		void SetNumberOfSteps(const int & N){Nsteps = N;};
		
		//methods to specify which resolution method should be used by plot(), print() and save()
		void SetTheta(const double & theta);
		
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
		
		// definition of computing parameter
		int Nsteps = 100;	//Number of steps
		std::array<double,4> thetas{0.5,0.,1.,0.5}; //thetas corresponding to each method
		double lastTheta = 0.5; //Save the last theta used
		int solutionToUse = 3;	//default solution to use is CN
		
		// Method that actually call the solver. All public solving method call this method.
		NumSolution CallSolver(const int method);
		
		// To avoid multiple computation of the solutions the class
		// save the solution as data member. If a solution is called then the 
		// class return the value already computed.
		// The arry ComputedSolution indicate whitch solution has been already computed
		// 0: generic theta, 1: EF, 2: EB, 3: CN
		std::array<bool,4> ComputedSolution{false,false,false,false};
		
		// Array with the solution of the methods
		std::array<NumSolution,4> Solutions; // 0: generic theta, 1: EF, 2: EB, 3: CN
	

};

#include <iostream>
#include <cmath>
#include "cauchyProblem.hpp"	// Class to handle Cauchy problems
//#include "gnuplot-iostream.hpp"

using ODE = std::function<double(double,double)>;

int main(){
// ODE of the challenge
	const ODE ChallengeOde = [](double t, double y){return -t*exp(-y);}; 
	
//Other ODE's
	const ODE odeTest1 = [](double t, double y){return 2*y;};
	const ODE odeTest2 = [](double t, double y){return cos(3*t) + y/tan(2*t);};
	
//Declaration and initialization of Cauchy problems
	CauchyProblem challengeProblem(ChallengeOde);
	
	// (ode, initial value, initial time, end time)
	CauchyProblem testCP1(odeTest1, 2, 1.2, 3);
	CauchyProblem testCP2(odeTest2, 0, 0, 6);
	
//Set resolution parameters
	testCP1.SetNumberOfSteps(200);
	testCP2.SetNumberOfSteps(10000);

//Plots
	challengeProblem.plot();
	testCP1.plot();
	testCP2.plot();

//Print solution
	challengeProblem.print();
	
//Save solution
	challengeProblem.save();
	
	return(0);
}



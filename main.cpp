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
	const ODE odeTest2 = [](double t, double y){return cos(t) + y/tan(t);};
	
	//Declaration and initialization of Cauchy problems
	CauchyProblem ChallengeProblem(ChallengeOde);
	
	CauchyProblem TestCP(odeTest1, 2, 1.2, 3);
	TestCP.SetNumberOfSteps(1000);
	
	ChallengeProblem.CNSolution();
	ChallengeProblem.plot();
	
	TestCP.CNSolution();
	TestCP.plot();
	
	
	return(0);
}



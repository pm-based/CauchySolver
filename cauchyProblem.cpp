#include "cauchyProblem.hpp"

// Call the Solver if the solution of the selected method has not been computed, return the soluton of the selected theta method
NumSolution CauchyProblem::CallSolver(const int method){
	//check if the solution has been already computed, and in the case of the general theta method check if the theta has not changed. If theta is changed then compute the solution
	if ((ComputedSolution[method] == false) or (method == 0 and thetas[0] != lastTheta)) {
		Solutions[method] = Solver(odefun, InitialValue, InitialTime, EndTime, Nsteps, thetas[method]);
		ComputedSolution[method] = true; // Set that the solution with selected method has been computed
		if (method == 0) {lastTheta = thetas[0];} //in the case of general theta update the value of the last theta.
	}
	solutionToUse == method; //The last computed method is setted as the solution to use by print(), plot() and save()
	return (Solutions[method]);
}

// Return the solution of the generic theta method by means CallSolver
NumSolution CauchyProblem::ThetaSolution(const double & theta){
	SetTheta(theta);	
	return(CallSolver(solutionToUse));
}

// Set the correct resolution method to use from theta, and if necessary update the value of thatas[0] that correspond to the theta value of the generic theta method
void CauchyProblem::SetTheta(const double & theta){
	// If theta is not between 0 and 1
	if (theta < 0 or theta > 1) {
		std::cout << "theta must be in [0,1]. Using theta = 1/2." << std::endl;
		solutionToUse = 3; // Use CN
		return;
	}
	// If theta corrispond to EF or EB or CN
	if(theta == 0){
		solutionToUse = 1; // Use EF
		return;
	}
	if(theta == 1){
		solutionToUse = 2; // Use EB
		return;
	}
	if(theta == 0.5){
		solutionToUse = 3; // Use CN
		return;
	} else {
	// For a generic valid theta differtent form 0, 1 or 0.5
	solutionToUse = 0; // Use generic theta method
	thetas[0] = theta; //Update the value of theta for the generic method
	return;
	}
}

// Plot whit gnuplot the solution of the selected theta method
void CauchyProblem::plot(){
	// Compute the solution if necessary
	if (ComputedSolution[solutionToUse] == false){CallSolver(solutionToUse);};
	
	Gnuplot gp; // gnuplot iostream
	gp << "plot" << gp.file1d(Solutions[solutionToUse]) << "notitle"<< std::endl;
	return;
}

// Print the solution of the selected theta method
void CauchyProblem::print(){
	// Compute the solution if necessary
	if (ComputedSolution[solutionToUse] == false){CallSolver(solutionToUse);};
	
	for(int i = 0; i <= Nsteps; i++){
		std::cout<<"u(" << std::get<0>(Solutions[solutionToUse])[i] << ") =" <<
		 std::get<1>(Solutions[solutionToUse])[i] << std::endl;
	};
	return;
}

// Save in file (Solution.txt) the solution of the selected theta method
void CauchyProblem::save(){
	if (ComputedSolution[solutionToUse] == false){CallSolver(solutionToUse);};
	
	std::cout << "Saving solution..." << std::endl;
	std::ofstream file("Solution.txt");
	file << "solution of the cauchy problem: " << std::endl;
	for(int i = 0; i <= Nsteps; i++){
		file<<"u(" << std::get<0>(Solutions[solutionToUse])[i] << ") = " <<
		 std::get<1>(Solutions[solutionToUse])[i] << std::endl;
	};
	std::cout << "Solution saved in Solution.txt" << std::endl;
	return;
}

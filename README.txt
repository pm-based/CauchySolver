# Cauchy Problem Solver

This project defines a Cauchy problem and provides various methods to calculate, visualize, and save numerical solutions. The `CauchyProblem` class is designed specifically for defining a Cauchy problem, with parameters that describe the mathematical problem remaining unmodifiable. However, parameters related to the numerical solution, such as the number of steps and the `theta` parameter, can be adjusted.

## Features

The `CauchyProblem` class implements four numerical schemes to solve the problem:
- **Forward Euler**: `EFSolution()`
- **Backward Euler**: `EBSolution()`
- **Crank-Nicolson**: `CNSolution()`
- **General Theta Scheme**: `ThetaSolution(theta)`

Each method returns the solution as a `NumSolution`, which is defined as a `std::tuple<std::vector<double>, std::vector<double>>`. 
- The first vector contains the time points at which the solution is evaluated.
- The second vector contains the corresponding values of the solution at those time points.

### Solution Storage

Each solution calculated using one of the four methods is saved in an internal array (`Solutions`) to avoid redundant recalculations with the same method. In particular, for `ThetaSolution`, the solution is stored for the most recent value of `theta`. If `theta` remains unchanged, the solution is not recalculated.

### Visualization and Output

The `CauchyProblem` class provides three methods to manage the calculated solution:
- **Print**: `print()` outputs the solution to the console.
- **Plot**: `plot()` visualizes the solution using Gnuplot.
- **Save**: `save()` saves the solution to a file.

By default, these methods use the most recently calculated solution. You can select a different solution using `SetTheta(theta)`. If the requested solution has not yet been computed, it will be calculated automatically when needed.

### Constructors

The class provides two constructors:
1. `CauchyProblem(ODE f, double y0, double t0, double t1)` – Fully defines the Cauchy problem.
2. `CauchyProblem(ODE f)` – Requires only the ODE to be solved, and defaults to `y0 = 0`, `t0 = 0`, `T = 1`.

## Solver Class

The `Solver` class calculates the solution using the finite difference method with a general `theta` parameter. For root-finding within the solver, the secant method implemented in `basicZeroFun.hpp` is used. To compute the derivative, the endpoints of the interval centered at the previous result `u[i-1]` are used, with a width equal to `2*(2*odefun(t[i],u[i-1])+0.01)`.

## Requirements

- You must integrate the project with the repository [pacs-examples](https://github.com/pacs-course/pacs-examples.git): Set the path to `pacs-examples` in the `PATH_PACSEXAMPLE` variable in the Makefile. This is necessary because the project uses the `basicZeroFun.hpp` file and its associated libraries.
- The `Boost` library is required for using Gnuplot to visualize the results.

## Compilation

To compile the project, follow these steps:
1. Clone the `pacs-examples` repository:
   ```bash
   git clone https://github.com/pacs-course/pacs-examples.git

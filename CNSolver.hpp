#include <tuple>
#include <functional>
#include <vector>
#include "/home/p2/PACS/pacs-examples/Examples/src/LinearAlgebraUtil/basicZeroFun.hpp"


std::tuple<std::vector<double>, std::vector<double>> CNSolver(const std::function<double(double,double)>& f, const double & y0, const double & T, const int & N);

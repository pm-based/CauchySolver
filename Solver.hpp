#include <tuple>
#include <functional>
#include <vector>
#include "basicZeroFun.hpp"


std::tuple<std::vector<double>, std::vector<double>> Solver(const std::function<double(double,double)>& odefun, const double & y0,const double & t0 ,const double & T, const int & N, const double & theta);

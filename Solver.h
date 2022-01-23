#ifndef SOLVER_H
#define SOLVER_H

#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <iomanip>

#define G 9.81

class Solver {
	protected:
		// Members are accessible by derived classes but not made public
		void parse(std::vector<double> pParams);
		void xy_conv();
		void write();

		// Pure virtual function provides interface framework
		virtual void solve() = 0;
		
		// Initialising solution parameters
		std::vector<double> params = std::vector<double>(4);
		std::vector<double> v = std::vector<double>(4);
		std::vector<double> m = std::vector<double>(4);
		std::vector<double> l = std::vector<double>(4);
		
		double h;
		double T_max;
		unsigned int ts;
		unsigned int iters;

		std::fstream output;
		
		// To store instantaneous values
		std::vector<double> v_prev = std::vector<double>(4);
		std::vector<double> f = std::vector<double>(4);
		std::vector<double> x = std::vector<double>(2);
		std::vector<double> y = std::vector<double>(2);

	public:
		// Constructor
		Solver(std::vector<double> pParams);

		// Destructor
		~Solver();
};

// Declaring standalone function v_dot - specific to the problem
// Better practice is to declare v_dot as a friend function in Solver but v_dot becomes illegible :(
void v_dot(std::vector<double> &f, std::vector<double> &l, std::vector<double> &m, std::vector<double> &v);


#endif // SOLVER_H

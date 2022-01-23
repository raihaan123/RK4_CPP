#ifndef RK4_H
#define RK4_H

#include "Solver.h"

class RK4 : public Solver {
	private:
		// These attributes are specific to the RK4 method hence made private
		std::vector<std::vector<double>> K;
		
	public:
		// Constructor
		RK4(std::vector<double> pParams);
		void solve();
};


#endif
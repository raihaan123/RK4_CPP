/*	Runge-Kutta 4 Solver derived class for the Double Pendulum problem
   	CID: 01707131	*/

#include "RK4.h"

using namespace std;

// Constructor with initializer list
RK4::RK4(vector<double> pParams) : Solver(pParams){
	parse(pParams);
	K.resize(4, vector<double>(4,1));
}

// RK4 algorithm implemented here
void RK4::solve(){
	// Solving for the required timesteps 'ts'
	// 'iters' tracks iteration number, declared in Solver.h
	for (iters = 1; iters <= ts; ++iters){

		// Save previous state
		copy(v.begin(), v.end(), v_prev.begin());
		
		// Iterate to find k1, k2, k3 and k4, stack rows into 4x4 K 'matrix'
		for (unsigned int i = 0; i < 3; ++i){
			
			// Compute derivative f using v_dot - parameters passed by reference
			v_dot(f, l, m, v);
			
			transform(f.begin(), f.end(),
					  K[i].begin(), [=] (double x) { return h * x; } );
			
			// Prepare the next call to v_dot
			transform(K[i].begin(), K[i].end(), v_prev.begin(),
					  v.begin(), [=] (double x, double y) { return y + x/2; } );
		}
		
		// k4 is slightly different
		transform(K[2].begin(), K[2].end(), v_prev.begin(),
		  v.begin(), [=] (double x, double y) { return y + x; } );
		  
		v_dot(f, l, m, v);
		transform(f.begin(), f.end(),
		  K[3].begin(), [=] (double x) { return h * x; } );
		
		
		// Update current state
		for (unsigned int i = 0; i < 4; ++i){
			v[i] = v_prev[i] + K[0][i]/6 + (K[1][i] + K[2][i])/3 + K[3][i]/6;
		}
		
		// Convert DoFs v1 and v2 to cartesian space
		xy_conv();
		
		// Append to file
		write();
	}
}
/*	Solver base class for the Double Pendulum problem
   	CID: 01707131	*/

#include "Solver.h"

using namespace std;

// Constructor with initializer list
Solver::Solver(std::vector<double> pParams) : params(pParams){
	// Open output file
	output.open( "output.txt", ios::out | ios::trunc );
}

// Destructor
Solver::~Solver(){
	// Close output file
	output.close();
}

void Solver::parse(vector<double> pParams){
	cout << "Parsing solution parameters... ";

	// Copying the vectors for cleaner code below :)
	copy(params.begin(), params.begin()+2, m.begin());
	copy(params.begin()+2, params.begin()+4, l.begin());
	copy(params.begin()+4, params.begin()+6, v.begin());
	
	// Adding the zero initial velocity constraint
	v[2] = 0.0;
	v[3] = 0.0;
	
	h = { params[6] };
	T_max = { params[7] };
	ts = (int)(T_max / h);

	cout << "Done!\n" << "Running solver... " << endl;

	// Derived class now implements solution method
	
	output << setw(15) << "t"
		   << setw(15) << "x1"
		   << setw(15) << "y1"
		   << setw(15) << "x2"
		   << setw(15) << "y2" << endl;

	// Compute cartesian form and output first line (initial condition)
	xy_conv();
	write();
}

void Solver::xy_conv(){
	// Convert degrees of freedom v_1 and v_2 to 2D cartesian coordinates
	x[0] = l[0] * sin(v[0]);
	y[0] = -l[0] * cos(v[0]);
	x[1] = x[0] + l[1] * sin(v[1]);
	y[1] = y[0] - l[1] * cos(v[1]);
}

void Solver::write(){

	// Write calculated coordinates to 'output.txt'
	output.precision(6);
	output << setw(15) << (iters * h)
		   << setw(15) << x[0] 
		   << setw(15) << y[0] 
		   << setw(15) << x[1] 
		   << setw(15) << y[1] << endl;
}
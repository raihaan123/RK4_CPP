/*	The Double Pendulum Problem!
   	CID: 01707131	*/

#include <iostream>
#include <vector>
#include "read.h"
#include "RK4.h"

using namespace std;

int main() {
	
	cout << "Welcome to the Double Pendulum RK4 Solver!\n" << endl;
	
	// Read and parse the parameters given in the text file into a vector<double>(8)
	cout << "Reading file... ";
	vector<double> vParams = readFile();
	cout << "Done!" << endl;
	
	// Creating an RK4 Solver object with parsed parameters
	RK4 myAwesomeSolver(vParams);
	myAwesomeSolver.solve();
	
	cout << "Solved!" << endl;
	
	return 0;
}
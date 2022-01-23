#include "read.h"

using namespace std;

vector<double> readFile(string filename){
	vector<double> raw_params;
	
	ifstream file ( filename , ios::in );
	if (!file.is_open()){
		cout << "Problem opening the file!\n";
		exit(1);
	}
	
	string temp;
	double converted;
	
	try{
		for (unsigned i = 0; !file.eof(); ++i){
			file >> temp;
			// Converting to double
			istringstream S(temp);
			S >> converted;
			raw_params.push_back(converted);
		}
	} catch(const exception &e) {
		cerr << "Bad parameters!\n" << e.what();
		exit(1);
	}
	
	file.close();
	return raw_params;
}
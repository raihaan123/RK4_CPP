#ifndef READ_H
#define READ_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

// Read function
std::vector<double> readFile(std::string filename = "parameters.txt");

#endif
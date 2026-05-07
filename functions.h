#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void FileInput(ifstream& inputFile);
void getAllVectors(ifstream& inputFile, vector<int>& xCoords, vector<int>& yCoords, vector<string>& charValues);
int stringToInt(string str);
int getMaxX(const vector<int>& xCoords);
int getMaxY(const vector<int>& yCoords);
void sortVectors(vector<int>& xCoords, vector<int>& yCoords, vector<string>& charValues);

#endif // FUNCTIONS_H
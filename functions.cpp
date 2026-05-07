#include "functions.h" 
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;   

//Function to convert the coordinates to integers
int stringToInt(string str) {
    int result = 0;
    for (int i = 0; i < str.length(); i++) {
        result = result * 10 + (str[i] - '0');
    }
    return result;
}

//Function to extract the input file
void FileInput(ifstream& inputFile) {
    inputFile.open("InputData.csv");

    if (!inputFile.is_open()) {
        cout << "Error opening file" << endl;
        return;
    }
}

//Function to extract all vectors from the input file
void getAllVectors(ifstream& inputFile, vector<int>& xCoords, vector<int>& yCoords, vector<string>& charValues) {
            string line;
            while(getline(inputFile, line)) {
                line.pop_back(); //removes the trailing newline character
                int commaPos1, commaPos2, xCoordInt, yCoordInt;
                string xCoord, yCoord, charValue;
                commaPos1 = line.find(',');
                commaPos2 = line.find(',', commaPos1 + 1);

                xCoord = line.substr(0, commaPos1);
                xCoordInt = stringToInt(xCoord);
                xCoords.push_back(xCoordInt);
                
                charValue = line.substr(commaPos1 + 1, commaPos2 - commaPos1 - 1);
                charValues.push_back(charValue);

                yCoord = line.substr(commaPos2 + 1);
                yCoordInt = stringToInt(yCoord);
                yCoords.push_back(yCoordInt);
            }
}


//Function to get the maximum x-coordinate
int getMaxX(const vector<int>& xCoords) {
    int maxX;
    maxX = xCoords[0];
    for (int i = 1; i < xCoords.size(); i++) {
        if (xCoords[i] > maxX) {
            maxX = xCoords[i];
        }
    }
    return maxX;
}

//Function to get the maximum y-coordinate
int getMaxY(const vector<int>& yCoords) {
    int maxY;
    maxY = yCoords[0];
    for (int i = 1; i < yCoords.size(); i++) {
        if (yCoords[i] > maxY) {
            maxY = yCoords[i];
        }
    }
    return maxY;
}

//Function to sort the vectors by their coordinates
void sortVectors(vector<int>& xCoords, vector<int>& yCoords, vector<string>& charValues) {
    for (int i = 0; i < xCoords.size() - 1; i++) {
        for (int j = 0; j < xCoords.size() - i - 1; j++) {
            if ((xCoords[j] > xCoords[j + 1]) || 
                (xCoords[j] == xCoords[j + 1]) && (yCoords[j] > yCoords[j + 1])) {
                swap(xCoords[j], xCoords[j + 1]);
                swap(yCoords[j], yCoords[j + 1]);
                swap(charValues[j], charValues[j + 1]);
            }
        }
    }
}

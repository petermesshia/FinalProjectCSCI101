#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "functions.h"

using namespace std;

int main() {
    //Opening the input file
    ifstream inputFile;
    FileInput(inputFile);

    int i, j; //loop variables
    string line; //Will be used to store each line of the input file

    //Assigning vectors to extract the data from the input file
    vector<int> xCoords; 
    vector<int> yCoords; 
    vector<string> charValues; 

    //Skipping the header line
    getline(inputFile, line);

    //Populating the vectors with the data from the input file
    getAllVectors(inputFile, xCoords, yCoords, charValues);

    //Getting the maximum x and y coordinates
    int maxX = getMaxX(xCoords);
    int maxY = getMaxY(yCoords);

    //Sorting the vectors by their coordinates
    sortVectors(xCoords, yCoords, charValues); 

    //Creating the 2D array and initializing it with spaces
    string outputArray[maxY + 1][maxX + 1];
    for (i = 0; i <= maxY; i++) {
        for (j = 0; j <= maxX; j++) {
            outputArray[i][j] = " ";
        }
    }

    //Fill the array with the character values
    for (i = 0; i < xCoords.size(); i++) {
        outputArray[yCoords[i]][xCoords[i]] = charValues[i];
    
    }

    //Print the 2D array
    for (i = 0; i <= maxY; i++) {
        for (j = 0; j <= maxX; j++) {
            cout << outputArray[i][j];
        }
        cout << endl;
    }

    //Close the input file
    inputFile.close();

    return 0;
}
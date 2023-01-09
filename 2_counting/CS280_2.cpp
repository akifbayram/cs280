#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	string fileName;	
	cout << "Enter the name of a file to read from:"; // Prompt
	cin >> fileName;
	cout << endl << endl;
	
	ifstream inFile; 
	inFile.open(fileName.c_str()); // Convert string to C string type
	
	if ( !inFile ) { // Overloaded ! operator
	
		cout << "File cannot be opened " << fileName << endl;
		return 0;	
	}
	
	int countLines = 0, countRun = 0, countPrint = 0, countCopy = 0, countDelete = 0, countInvalid = 0, countValid = 0, countComment = 0;
	string input;
	getline(inFile, input, '\n'); //
	while ( !inFile.eof() ) {
		
		if ( isspace(input[0]) ) {
		}
		else if ( input.empty() ) {
		}
		else if ( input.find("%") != -1 ) {
			countComment += 1;
		}
		else if ( input.find("run") != -1 ) {
			countRun += 1;
			countValid += 1;
		}
		else if ( input.find("print") != -1 ) {
			countPrint += 1;
			countValid += 1;
		}
		else if ( input.find("copy") != -1 ) {
			countCopy += 1;
			countValid += 1;
		}
		else if ( input.find("delete") != -1 ) {
			countDelete += 1;
			countValid += 1;
		}
		else {
			cout << "Error: Unrecognizable command in line " << countLines + 1 << "\n\n";
            countInvalid += 1;
		}
		countLines += 1;
		getline(inFile, input, '\n'); // Placed at end of loop to reach EOF 
	}
	
	cout << "Total Number of Lines: " << countLines << "\nNumber of non-blank lines: " << countNonBlank << "\nNumber of Words: " << countWords; 
	cout << "\nNumber of Integers: " << countIntegers << "\nNumber of Names: " << countNames << endl;
}
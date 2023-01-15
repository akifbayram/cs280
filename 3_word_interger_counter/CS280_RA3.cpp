#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

// Check name function
bool checkName(string str) {
	if ( str[0] == '_' || isalpha(str[0]) ) { // If first char is underscore or is alpha
		for ( int i = 1; i < str.length(); i++ ) { // Loop through chars in string
			if ( !isalpha(str[i]) && !isdigit(str[i]) ) { // If chars is not alpha and not digit
				if ( str[i] != '@' && str[i] != '_' ) { // If chars is not _ or @
					return false; 
				}
			}
		}
		return true; // After loop
	}
	return false;
}

// Check integer function
bool checkInteger(string str) {
	if ( (str[0] == '-' || str[0] == '+') && !isdigit(str[1]) ) { // First char is (- or +) AND second char doesn't have a digit following
		return false;
	}
	if ( str[0] == '-' || str[0] == '+' || isdigit(str[0]) ) { // First char is - or + or is digit
		for ( int i = 1; i < str.length(); i++) {
			if (isdigit(str[i]) == false) {
				return false;
			}
		}
		return true;		
	}
	return false;
}

int main( int argc, char *argv[]) {
	ifstream inFile;
	
	if ( argc > 1 ) { // If arguments present
		inFile.open(argv[1]); // arg[1] argument must be file name
		if ( inFile.is_open() ) {} // If file can be opened
            
		else {
			cout << "CANNOT OPEN THE FILE " << argv[1] << endl;
			return 0;
		}
	}
	else if ( argc == 1 ) { // no arguments present
		cout << "NO SPECIFIED INPUT FILE NAME." << endl;
		return 0;
	}
    
	string input, word;
	int countLines = 0, countBlank = 0, countIntegers = 0, countNames = 0, countWords = 0, countWordsInLine = 0;
    
	while ( getline(inFile, input, '\n') ) { // Loop through each line in file
        istringstream line(input); 
        countWordsInLine = 0; // Reset counter each loop
        while ( line >> word ) { // Loop through each word in the line
            countWordsInLine++;
            if ( checkName(word) ) {
                countNames++;
            }
            else if ( checkInteger(word) ) {
                countIntegers++;
            }
            countWords++; // Increment word counter each successful loop
            
        }
        if (countWordsInLine == 0) 
            countBlank++; // Increment blank line counter for each empty line
		countLines += 1;
	}
	
	if ( countLines == 0 ) {
		cout << "File is empty." << endl;
		return 0;
	}
	
	// Command line arguments
	string currentFlag;
	bool all = false, integers = false, names = false;
    
    for ( int i = 2; i < argc; i++ ) { // Loop through command line arguments, flag if found
    	currentFlag = argv[i]; 
        if ( currentFlag == "-all" ) 
        	all = true;
        else if ( currentFlag == "-ints" ) 
        	integers = true;
        else if ( currentFlag == "-names" ) 
        	names = true;
        else if ( currentFlag != "-all" && currentFlag != "-ints" && currentFlag != "-names" ) { // If unrecog. flag found, end
            cout << "UNRECOGNIZED FLAG " << argv[i] << endl;
            return 0;
		}
	}
	
	cout << "Total Number of Lines: " << countLines << endl;
	cout << "Number of non-blank lines: " << countLines - countBlank << endl;
	cout << "Number of Words: " << countWords << endl;
	if ( integers || all )
		cout << "Number of Integers: " << countIntegers << endl;
	if ( names || all )
		cout << "Number of Names: " << countNames << endl;                   
}
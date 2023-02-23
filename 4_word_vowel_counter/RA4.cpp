#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map> 

using namespace std;

// count vowels function, return int of vowels
int numVowels(string str) {
	int count = 0;
	for ( int i = 0; i < str.length(); i++ ) { // Loop through chars in string
		if ( str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'  || str[i] == 'A'  || str[i] == 'E'  || str[i] == 'I'  || str[i] == 'O'  || str[i] == 'U' ) {
			count++;		
		}
	}
	return count;
}

int main( int argc, char *argv[]) {
	ifstream inFile;
	
	// File check
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

    int wordVowels = 0, countLines = 0, countWords = 0, 
        vowelsNone = 0, vowelsOne = 0, vowelsTwo = 0, 
        vowelsThreePlus = 0;
	string input, word;
	map<int, map<string, int>> Group;
	
	while ( getline(inFile, input, '\n') ) {
        countLines++; // Line counter
        istringstream line(input); 
        while ( line >> word ) { // Loop through each word in the line
            countWords++; // Word counter
            wordVowels = numVowels(word); // Call numVowels function
            if ( wordVowels == 0 ) {
            	vowelsNone++; // Increment
            	Group[0][word]++; // Map to directory [0][word][increment occurences]
			}
			else if ( wordVowels == 1 ) {
            	vowelsOne++;
            	Group[1][word]++;
			}
			else if ( wordVowels == 2 ) {
            	vowelsTwo++;
            	Group[2][word]++;
			}
			else {
            	vowelsThreePlus++;
            	Group[3][word]++;
			}
    	}
    }
    
	if ( countLines == 0 ) {
		cout << "File is empty." << endl;
		return 0;
	}
	
	cout << "Number of words in the file: " << countWords << endl;
	cout << "Number of words with no vowels in the file: " << vowelsNone << endl;
	cout << "Number of words with one vowel in the file: " << vowelsOne << endl;
	cout << "Number of words with two vowels in the file: " << vowelsTwo << endl;
	cout << "Number of words with three or more vowels in the file: " << vowelsThreePlus << endl;
	
	map<int, map<string, int>>::iterator it;
	if ( vowelsNone != 0 ) {
		cout << "\nList of Words with no vowels and their number of occurrences:" << endl;
		for ( auto it : Group[0] ) {
			cout << it.first << ": " << it.second << endl;
		}
	}
	if ( vowelsOne != 0 ) {
		cout << "\nList of Words with one vowel and their number of occurrences:" << endl;
		for ( auto it : Group[1] ) {
			cout << it.first << ": " << it.second << endl;
		}
	}
	if ( vowelsTwo != 0 ) {
		cout << "\nList of Words with two vowels and their number of occurrences:" << endl;
		for ( auto it : Group[2] ) {
			cout << it.first << ": " << it.second << endl;
		}
	}
	if ( vowelsThreePlus != 0 ) {
		cout << "\nList of Words with three or more vowels and their number of occurrences:" << endl;
		for ( auto it : Group[3] ) {
			cout << it.first << ": " << it.second << endl;
		}
	}
}
// Rabin Karp pattern match algorithm 
// This algorithm looks for small pattern "pat" in large text "txt"

#include <iostream>
#include <cstring>
#include <fstream>
#include <string>

using namespace std;

const unsigned short int alphaCount = 256; // Number of character in alphabet
const unsigned short int divisor 	= 101; // Divisor to be used for generating modulo hash (should be prime)
// const char * fileName 

// Function :  Search : Compares and looks for string patter in large search text
// pat : 		Pattern to be searched
// txt : 		The divisor used for calculating hash values, used in search
// Returns : 	Column no. if the element is found

size_t  search(const char * pat, const char * txt, int divisor)
{
	size_t patLen = std::strlen ( pat );
	size_t txtLen = std::strlen ( txt );

	int patHash = 0;  // Hash value for  the pattern to be searched
	int txtHash = 0;  // Hash value for the text

	int i,j;

	//int charHash = 1;

	int h = 1;
	if (txtLen < patLen)
	{
		std::cout << "Pattern match not found in the text." << std::endl;
		return 0;
	}

	//  h = (alphaCount ^ patLen-1 ) % divisor
	for (i = 0; i < patLen-1; ++i)
	{
		h = (h * alphaCount) % divisor;
	}

	// Calculate the initial hashes
	for (i = 0; i < patLen; ++i)
	{
		// newHash = ( (dictionarySize) * oldHash + 'newCharacter') % divisor
		patHash = (alphaCount * patHash + *(pat+i)) % divisor;
		txtHash = (alphaCount * txtHash + *(txt+i)) % divisor;
	}

	for (i = 0; i < txtLen - patLen; ++i)
	{
			// cout << patHash << ", " << txtHash << endl;
		if (patHash == txtHash)		// If the hash match was found
		{
			for (j = 0; j < patLen; ++j)
			{
				if( *(pat+j) != *(txt + i + j) ) // If any character mismatches
					break;
			}

			if (j == patLen)		// If we were able to successfully compare all characters after hash match
			{
				std::cout << "Pattern match found at location " << i << std::endl;
				return i;
			}
		}

		// Proceed to next window for hashing the values
		if ( i < txtLen - patLen )	// If we have not exhausted all characters in text and have sufficient characters to successfully compare
		{
			// Remove the hash contribution from trailing character
			// and add the none from the new incoming character
			// Hash =  (dictionarySize X [oldHash - (oldChar X h) + newChar] ) % divisor
			txtHash = ( alphaCount * (txtHash - *(txt+i)*h) + *(txt + i + patLen) ) % divisor;
			if (txtHash < 0)
				txtHash += divisor;
		}

	}
	return 0 ; // Did not find match
}


int main(int argc, char const *argv[])
{
	const char * txt = "Why so serious ?!";
	const char * pat = "serious";
	search (pat, txt, divisor);

	// Following code demonstrates the pattern search in a file
	// std::ifstream theFile;
	// size_t lineCount = 0;
	// const char * fileName = "example.txt";
	// theFile.open(fileName);
	// std::string line;
	// std::cout << "Searching for '" << pat << "' in file : " << fileName << std::endl;

	// if (theFile.is_open())
	// {
	// 	std::cout << "File Opened." << std::endl;
	// 	while( std::getline (theFile, line) )	// Read the next line from the file
	// 	{
	// 		if ( search(pat, line.c_str(), divisor) )	// if found something
	// 			std::cout << lineCount << " : "<< line << std::endl;
	// 	}
	// 	theFile.close();
	// }

	return 0;
}
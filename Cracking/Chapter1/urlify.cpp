#include <iostream>
#include <string>

// Ask if it should return a new string or modify the existing string
// Assume modify existing string because it has the space for the extra chars
// Length is the actual length of the string without the spaces
// but the object has extra space at the end to accommodate the shifting of the chars
void urlify(std::string &str, int length){
	int rearIndex = str.length() - 1;
	char replace[] = {'%', '2', '0'}; 
	// Shift letters over to the end as necessary
	for (int i = length; i >= 0; i--){
		if (str[i] == ' '){
			// Add the three chars for a space
			for (int k = 2; k >= 0; k--){
				str[rearIndex] = replace[k];
				rearIndex--;
			}
		} else {
			str[rearIndex] = str[i];
			rearIndex--;
		}
	}
}

int main(){
	std::string test = "This is a string      ";
	int length = 15;
	urlify(test, length);
	std::cout << test << std::endl;
}

#include <iostream>
#include <string>

// Operates in O(n) time and 0(1) space
// Time: must touch every letter in s to determine uniqueness
// Space: no matter the length of s, allocate a 128 integer array 
// 128 for every possible ASCII char 
bool isUnique(std::string s){
	if (s.length() > 128){
		return false;
	}
	// Pigeonhole principle: s cannot be unique if it has
	// more chars than possible values for those chars
	int chars[128] = {0};
	for (char c : s){
		chars[c]++;
		if (chars[c] > 1){
			return false;
		}
	}
	return true;
}

int main(){
	std::cout << isUnique("Test") << std::endl;
}

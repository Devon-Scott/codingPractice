#include <iostream>
#include <string>
#include <map>

bool isPermutation(std::string &first, std::string &second){
	if (first.length() != second.length()){
		return false;
	}
	std::map<char, int> firstMap;
	for (char s : first){
		if (firstMap[s]){
			firstMap[s]++;
		} else {
			firstMap[s] = 1;
		}
	}

	std::map<char, int> secondMap;
	for (char s : second){
		if (!firstMap[s]){
			return false;
		} else {
			firstMap[s]--;
			if (firstMap[s] < 0){
				return false;
			}
		}
	}
	return true;
}

int main(){
	std::string test1_1 = "First";
	std::string test1_2 = "trsiF";
	std::cout << isPermutation(test1_1, test1_2) << std::endl;
	std::string test2_1 = "Testing";
	std::string test2_2 = "Testinn";
	std::cout << isPermutation(test2_1, test2_2) << std::endl;
}

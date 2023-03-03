#include <iostream>
#include <limits>
#include <vector>
using namespace std;

int solution(int A, int B, int K){
	// if i in [A, B] divides K
	int dividends = 0;
	if (K > B || (A == B && B != K)){
		return dividends;
	}
	int i;
	for (i = A; i <= B; i++){
		if (i % K == 0){
			break;
		}
	}	
	while (i <= B && i > 0){
		i += K;			
		dividends++;
	}
	return dividends;
}

int main(){
	std::cout << solution(6, 11, 2) << std::endl;
	std::cout << solution(0, 1, 11) << std::endl;
	std::cout << solution(0, INT_MAX, 2) << std::endl;
}

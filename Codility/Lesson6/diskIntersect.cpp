#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> &A){
	// Disks are guaranteed to intercept in their radii
	// Need to avoid overcounting pairs that have already been counted
	// That being those behind the index 
	// But also recognize when a circle is "reaching back" to add a count 
	std::sort(A.begin(), A.end(), [&](int a, int b){
		return a > b;
	});
	int intersections = 0;
	for (int i = 0; i < A.size(); i++){
		if (A[i] != 0){
			intersections += max(A[i] - i, 1);
		}
		if (intersections > 10000000){
			return -1;
		}
	}
	return intersections;
}

void printArray(vector<int> &A){
	for (int n : A){
		cout << n << ' ' << endl;
	}
	cout << endl;
}

int main(){
	vector<int> test = {1, 5, 2, 1, 4, 0};
	cout << solution(test) << endl;
	printArray(test);
}

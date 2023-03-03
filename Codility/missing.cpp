#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int solution(vector<int> &A){
	int min = 1;
	std::sort(A.begin(), A.end(), [](int a, int b)
	{
		return a < b;
	});
	for (int n : A){
		if (n == min){
			min++;
		} else if (n > min){
			break;
		}
	}
	return min;
}

int main(){

	vector<int> test1 = {1, 3, 6, 4, 1, 2};
	vector<int> test2 = {1, 2, 3};
	vector<int> test3 = {-1, -3};
	cout << solution(test1) << " " << solution(test2) << " " << solution(test3) << std::endl;
}

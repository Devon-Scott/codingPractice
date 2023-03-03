#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int solution(vector<int> &A) {
    // Implement your solution here
    int length = A.size();
    std::sort(A.begin(), A.end(), [](const int &a, const int &b){
        return a < b;
    });
    return max(A[0] * A[1] * A[length - 1], A[length - 1] * A[length - 3] * A[length - 2]);
}

int main(){
    std::vector<int> test1 = {-3, 1, 2, -2, 5, 6};
    std::vector<int> test2 = {-5, 5, -5, 4};
    std::cout << solution(test1) << std::endl;
    std::cout << solution(test2) << std::endl;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int checkMedian(vector<int> &A, int median){
    int first = A[median - 1], second = A[median], third = A[median + 1];
    if (first + second > third &&
        second + third > first &&
        third + first > second){
            return 1;
        }
    return 0;
}

int solution(vector<int> &A) {
    // Implement your solution here
    int length = A.size();
    std::sort(A.begin(), A.end(), [](const int &a, const int &b){
        return a < b;
    });
    if (length < 3){
        return 0;
    }
    for (int i = 1; i < length - 1; i++){
        long long int first = A[i - 1], second = A[i], third = A[i + 1];
        if (first + second > third &&
            second + third > first &&
            third + first > second){
                return 1;
            }
    }
    return 0;
}

int main(){
    vector<int> test1 = {10, 2, 5, 1, 8, 20};
    vector<int> test2 = {10, 50, 5, 1};
    std::cout << solution(test1) << " " << solution(test2) << std::endl;
}
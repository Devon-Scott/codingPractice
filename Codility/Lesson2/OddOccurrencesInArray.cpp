#include <vector>
#include <iostream>
#include <algorithm>

int solution(std::vector<int> &A) {
    // Implement your solution here
    int size = A.size();
    std::sort(A.begin(), A.end());
    for (int i = 0; i < size; i += 2){
        if (A[i] != A[i+1]){
            return A[i];
        }
    }
    return 0;
}

int main(){
    
}
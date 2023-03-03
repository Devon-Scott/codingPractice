#include <bitset>
#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> &A){
  std::cout << "{";
  for (int n: A){
    std::cout << n << ", ";
  }
  std::cout << "}" << std::endl;
}

vector<int> solution(vector<int> &A, int K) {
    // Implement your solution here
    if (K > A.size() && A.size() != 0){
      K = K % A.size();
    }
    if (K == 0 || A.size() == 0){
      return A;
    }
    vector<int> result(A.size());
    for (int i = 0, j = A.size() - K; i < K; i++, j++){
      result[i] = A[j];
    }
    for (int i = K, j = i - K; i < A.size(); i++, j++){
      result[i] = A[j];
    }
    return result;
}

int main(){
  vector<int> sample = {1, 2, 3, 4, 5};
  printVector(sample);
  vector<int> result = solution(sample, 7);
  printVector(result);
}

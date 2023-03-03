#include <iostream>
#include <vector>
#include <string>
using namespace std;

void printArray(vector<int> &A){
  std::cout << "(";
  int size = A.size();
  for (int i = 0; i < size; i++){
    std::cout << (i == size - 1 ? to_string(A[i]) : to_string(A[i]) + ", ");
  }
  std::cout << ")" << std::endl;
}

vector<int> solution(int N, vector<int> &A){
  vector<int> result(N);
  for (int i = 0; i < N; i++){
    result[i] = 0;
  }
  //printArray(result);
  int max = 0, size = A.size();
  for (int i = 0; i < size; i++){
    int counterIndex = A[i] - 1;
    if (counterIndex <= N - 1){
      result[counterIndex]++;
      int temp = result[counterIndex];
      if (temp > max){
        max = temp;
      }
    } else {
      for (int i = 0; i < N; i++){
        result[i] = max;
      }
    }
    //printArray(result);
  }
  return result;
}

vector<int> solution2(int N, vector<int> &A){
	int max = 0, size = A.size(), maxCounter = N - 1;
	vector<int> result(size, 0);
	// store the max value at the indices that had the max value inn
	vector<int> maximums(size);
	for (int n : A){
		int counterIndex = n - 1;
		if (counterIndex <= maxCounter){
			result[counterIndex]++;
			if (result[counterIndex] > max){
				max = result[counterIndex];
				maximums[
			}

		}
		
	}
	return result;
}

int main(){
  vector<int> test1 = {3, 4, 4, 6, 1, 4, 4};
  vector<int> sol = solution(5, test1);
  printArray(sol);
}

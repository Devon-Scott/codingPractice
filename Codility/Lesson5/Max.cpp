#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int> &A){
    cout << "(";
    for (int n : A){
        cout << n << ", ";
    }
    cout << ")" << endl;
}

vector<int> solution(int N, vector<int> &A) {
    // Implement your solution here
    vector<int> result(N, 0);
    
    // max and tempMax help sum the calls to maxCounter to apply at the end
    int max = 0, tempMax = 0, tempMin = 0, size = A.size();
    
    printArray(result);

    // let increase(X) be called, and keep track of the sum of maxCounter
    for (int i = 0; i < size; i++){
        int cIndex = A[i] - 1;
        if (cIndex <= N - 1){
            result[cIndex]++;
            int tempSample = result[cIndex];
            if (tempMin + tempSample > tempMax){
                tempMax = tempSample;
            }
        } else {
            max = tempMax;
            tempMax = 0;
            tempMin = max;
        }
        printArray(result);
    }
    
    // apply the remaining calls to maxCounter
    /*for (int i = 0; i < size; i++){
        result[i] += max;
    }*/
    return result;
}

int main(){
    vector<int> test = {3, 4, 4, 6, 1, 4, 4};
    vector<int> sol = solution(5, test);
    printArray(sol);
}
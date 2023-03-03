#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> &A){
    int length = A.size();
    int minimumIndex = 0;
    double minimumAverage = (A[0] + A[1]) / 2.0;
    //cout << minimumAverage << " at " << minimumIndex << endl;

    double avg1 = 0, avg2 = 0;
    for (int i = 0; i < length - 2; i++){
        avg1 = (A[i] + A[i + 1]) / 2.0;
        //cout << "avg1 is " << avg1 << endl;
        if (avg1 < minimumAverage){
            minimumIndex = i;
            minimumAverage = avg1;
        }
        avg2 = (A[i] + A[i + 1] + A[i + 2]) / 3.0;
        ///cout << "avg2 is " << avg2 << endl;
        if (avg2 < minimumAverage){
            minimumIndex = i;
            minimumAverage = avg2;
        }
        //cout << minimumAverage << " at " << minimumIndex << endl;
    }
    avg1 = (A[length - 1] + A[length - 2]) / 2;
    if (avg1 < minimumAverage){
        minimumIndex = length - 1;
        minimumAverage = avg1;
    }
    return minimumIndex;

}

int main(){
    std::vector<int> test1 = {4, 2, 2, 5, 1, 5, 8};
    std::vector<int> test2 = {-3, -5, -8, -4, -10};
    std::vector<int> test3 = {10, 10, -1, 2, 4, -1, 2, -1};
    std::cout << "Expected 1 got: " << solution(test1) << std::endl;
    std::cout << "Expected 2 got: " << solution(test2) << std::endl; 
    std::cout << "Expected 5 got: " << solution(test3) << std::endl;
}
// A disc of radius R at index I will always have 
// R - (min(N - I, 0)) discs inside it that are ahead of it
// In list of length 8, disc[6] = 5 will have 1 disc going forward (disc[7])
// To account for discs reaching back:
// if A[i - disc[i]] < disc[i], it is included in the count 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printArray(long long* L, int length){
    for (int i = 0; i < length; i++){
        std::cout << L[i] << " ";
    }
    std::cout << std::endl;
}

int solution(vector<int> &A){
    int numOfDiscs = 0, length = A.size();
    long long *leftBoundaries = new long long[length];
    long long *rightBoundaries = new long long[length];
    for (long long i = 0; i < length; i++){
        leftBoundaries[i] = i - A[i];
        rightBoundaries[i] = i + A[i];
    }
    auto sortFunc = [](const long long &a, const long long &b){
        return a < b;
    };
    std::sort(leftBoundaries, leftBoundaries + length, sortFunc);
    std::sort(rightBoundaries, rightBoundaries + length, sortFunc);
    printArray(leftBoundaries, length);
    printArray(rightBoundaries, length);

    int i = 0, j = 0;
    // i shows the right hand limits, j shows the left hand limits
    for (i; i < length; i++){
        while (j < length && rightBoundaries[i] >= leftBoundaries[j]){
            //std::cout << numOfDiscs << " += " << j << " - " << i << " = " << std::endl;
            numOfDiscs += (j - i);
            j++;
            //std::cout << numOfDiscs << std::endl;
        }
    }
    if (numOfDiscs > 10000000){
        return -1;
    }
    return numOfDiscs;

    // Idea for my old approach
    // Store an array of the ending values of each circle and compare when reaching back for an intersection
}

int main(){
    std::vector<int> test1 = {1, 5, 2, 1, 4, 0};
    std::vector<int> test2 = {1, 1, 1};
    std::vector<int> test3 = {1, 2147483647, 0};
    //std::cout << solution(test1) << std::endl;
    //std::cout << solution(test2) << std::endl;
    std::cout << solution(test3) << std::endl;


}
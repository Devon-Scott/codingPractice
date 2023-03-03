#include <iostream>
#include <vector>
#include <cmath>

int solution(std::vector<int> &A) {
    // Implement your solution here
    // Assume A.size >= 2
    int separator = 1, size = A.size();
    int leftSide = A[0], rightSide = 0;
    for (int i = 1; i < size; i++){
        rightSide += A[i];
    }
    // Rightside is now the sum of everything on the tape except the first index
    // Separator is located after the first index
    int min = abs(rightSide - leftSide);


    //std::cout << "P = " << separator << ", difference = |" << rightSide << " - " << leftSide << "| = " << min << std::endl; 


    // use separator + 1 because we don't want to include the last index of the array in the left side
    while (separator + 1 < size){
        
        rightSide -= A[separator];
        leftSide += A[separator];
        int difference = abs(rightSide - leftSide);
        //std::cout << "P = " << separator << ", difference = |" << rightSide << " - " << leftSide << "| = " << difference << std::endl; 
        if (difference < min){
            min = difference;
        }
        separator++;
    }
    return min;
}

int main(){
    std::vector<int> test = {3, 1, 2, 4, 3};
    std::vector<int> test2 = {-1000, 1000};
    std::cout << "****test one****" << std::endl;
    std::cout << solution(test) << std::endl;
    std::cout << "****test two****" << std::endl;
    std::cout << solution(test2) << std::endl;
}
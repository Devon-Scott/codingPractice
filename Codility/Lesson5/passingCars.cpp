#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> &A){
    int carsGoingEast = 0, passingCars = 0;
    for (int n : A){
        if (n == 0){
            carsGoingEast++;
        } else if (n == 1){
            passingCars += carsGoingEast;
            if (passingCars > 1000000000){
                return -1;
            }
        }
    }
    return passingCars;
}

int main(){
    std::vector<int> test = {0, 1, 0, 1, 1};
    std::cout << solution(test) << std::endl;
}
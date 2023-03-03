#include <iostream>
#include <vector>



int solution(int X, std::vector<int> &A) {

    bool *river = new bool[X];
    for (int i = 0; i < X; i++){
        river[i] = false;
        //std::cout << river[i] << std::endl;
    }
    int positions = 0, size = A.size();
    for (int i = 0; i < size; i++){
        if (!river[A[i] - 1]){
            river[A[i] - 1] = true;
            positions++;
            //std::cout << positions << std::endl;
        }
        if (positions == X){
            return i;
        }
    }
    return -1;
}

int main(){
    std::vector<int> sample = {1, 3, 1, 4, 2, 3, 5, 4};
    //std::vector<int> sample2 = {3, 4, 3, 4, 1, 4, 3, 6, 5, 5, 6, 3};
    std::cout << solution(5, sample) << std::endl;
    //std::cout << solution(6, sample2) << std::endl;
}
#include <iostream>
#include <vector>
#include <span>
using namespace std;

int sumArray(int* nums, int length){
    int sum = 0;
    for (int i = 0; i < length; i++){
        sum += nums[i];
    }
    return sum;
}
int maxSum(int* first, int* second, int length){    
    if (first == second){
        return *first
    }

    return max(sumArray(first, length), sumArray(second, length))
}

// I want a way to sum in place;
int maxSubArray(vector<int>& nums) {
    int length = nums.size() - 1;
    int* first = nums.data();
    int* second = nums.data() + 1;
    return maxSum(first, second, length)
    
}

int main(){

}
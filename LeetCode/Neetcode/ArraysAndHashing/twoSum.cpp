#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> result(2);
    int length = nums.size();
    // Brute force, gross
    for (int i = 0; i < length - 1; i++){
        if (nums[i] > target){
            continue;
        }
        for (int j = i + 1; j < length; j++){
            if (nums[j] > target){
                continue;
            }
            if (nums[i] + nums[j] == target){
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    return result;

    // recognize that some results are calculated twice?
}
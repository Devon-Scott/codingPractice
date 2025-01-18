/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

// @lc code=start
#include <vector>
#include <algorithm>
class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        std::vector<std::vector<int>> result;

        std::sort(nums.begin(), nums.end());

        if (nums.size() < 4){
            return result;
        }

        for (int start = 0; start < nums.size() - 3; start++){

            if (start > 0 && nums[start] == nums[start - 1]){
                continue;
            }

            for (int end = nums.size() - 1; end > start + 2; end--){
                
                if (end < nums.size() - 1 && nums[end] == nums[end + 1]){
                    continue;
                }
                
                int left = start + 1;
                int right = end - 1;

                while (left < right){
                    long a = nums[start];
                    long b = nums[left];
                    long c = nums[right];
                    long d = nums[end];
                    long sum = a + b + c + d;
                    if (sum == target){
                        result.push_back({nums[start], nums[left], nums[right], nums[end]});
                        while (left < right && nums[left] == nums[left + 1]){
                            left++;
                        }
                        while (left < right && nums[right] == nums[right - 1]){
                            right--;
                        }
                        left++;
                        right--;
                    }
                    else if (sum < target){
                        left++;
                    }
                    else{
                        right--;
                    }
                }
            }
        }
        return result;
    }    
};
// @lc code=end


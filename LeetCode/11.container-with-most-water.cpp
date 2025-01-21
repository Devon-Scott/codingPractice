/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
#include <vector>
class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int result = 0;
        int left = 0;
        int right = height.size() - 1;
        while (left < right){
            int y = std::min(height[left], height[right]);
            int x = right - left;
            result = std::max(result, x * y);
            height[left] < height[right] ? left++ : right--;
        }

        return result;
    }
};
// @lc code=end

// 65/65 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 24.52 % of cpp submissions (63 MB)
/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
#include <string>
#include <limits>
#include <iostream>
class Solution {
public:
    
    
    int myAtoi(std::string s) {
        int i = 0;
        long long result = 0;
        int sign = 1;

        while (s[i] == ' '){
            i++;
        }

        if (s[i] == '-'){
            sign = -1;
            i++;
        }
        else if (s[i] == '+'){
            i++;
        }

        while (s[i] >= 48 && s[i] <= 57){ // ASCII codes, might need a more robust checker for UTF
            int value = s[i] - 48;
            
            if (sign > 0){
                if (result > INT_MAX / 10 ||
                    (result == INT_MAX / 10 && value > (INT_MAX % 10))) {
                        return INT_MAX;
                    }
                    result = (result * 10) + value;
            }
            else {
                if (-result < INT_MIN / 10 ||
                    -result == INT_MIN / 10 && -value < (INT_MIN % 10)){
                        return INT_MIN;
                    }
                    result = (result * 10) + value;
            }

            i++;
        }
        return result * sign;
    }
};
// @lc code=end

// 1094/1094 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 80.55 % of cpp submissions (9 MB)
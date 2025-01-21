/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */

// @lc code=start
#include <limits>
#include <math.h>
class Solution {
public:
    int sgn(int val){
        return (0 < val) - (val < 0);
    }

    int divide(int dividend, int divisor) {
        if (divisor == 1){
            return dividend;
        }

        if (divisor == -1){
            if (dividend == INT_MIN){
                return INT_MAX;
            }
            return -dividend;
        }

        int sign = 1;
        if (sgn(dividend) != sgn(divisor)){
            sign = -1;
        }

        int quotient = 0;
        if (dividend == INT_MIN){
            if (divisor == INT_MIN){
                return 1;
            }
            while (dividend < divisor * sign){
                dividend += divisor * sign;
            }
        }
        
        while (std::abs(dividend) >= std::abs(divisor)){
            dividend -= divisor * sign;
            quotient++;
        }

        return quotient * sign;
    }
};
// @lc code=end


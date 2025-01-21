/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */

// @lc code=start
#include <string>
#include <iostream>
class Solution {
public:
    char* symbols = "MDCLXVI";
    int values[7] = {1000, 500, 100, 50, 10, 5, 1};

    std::string intToRoman(int num) {
        char result[20];
        int index = 0;

        for (int i = 0; i < 7; i += 2){
            int value = num / values[i];
            if (value == 9){
                result[index++] = symbols[i];
                result[index++] = symbols[i - 2];
            }
            else if (value == 4){
                result[index++] = symbols[i];
                result[index++] = symbols[i - 1];
            }
            else if (value >= 5){
                result[index++] = symbols[i - 1];
                for (int j = value; j > 5; j--){
                    result[index++] = symbols[i];
                }
            }
            else {
                for (int j = value; j > 0; j--){
                    result[index++] = symbols[i];
                }
            }
            num -= value * values[i];
        }
        return std::string(result);
    }
};
// @lc code=end

// 3999/3999 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 90.78 % of cpp submissions (8.6 MB)
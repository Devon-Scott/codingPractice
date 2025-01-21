/*
 * @lc app=leetcode id=223 lang=cpp
 *
 * [223] Rectangle Area
 */

// @lc code=start
#include <algorithm>
#include <iostream>
class Solution {
public:

    int area(int x1, int y1, int x2, int y2){
        return std::abs((x2 - x1) * (y2 - y1));
    }
    
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int areaA = area(ax1, ay1, ax2, ay2);
        int areaB = area(bx1, by1, bx2, by2);

        int ix1 = std::max(ax1, bx1);
        int ix2 = std::min(ax2, bx2);
        int iy1 = std::max(ay1, by1);
        int iy2 = std::min(ay2, by2);

        int intersect = 0;
        if (ix1 < ix2 && iy1 < iy2){
            intersect = area(ix1, iy1, ix2, iy2);
        }

        return areaA + areaB - intersect;
    }
};
// @lc code=end

// 3080/3080 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 37.43 % of cpp submissions (10.6 MB)


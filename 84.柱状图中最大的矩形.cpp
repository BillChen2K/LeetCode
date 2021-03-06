#include "header.h"
/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 *
 * https://leetcode-cn.com/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (42.93%)
 * Likes:    1366
 * Dislikes: 0
 * Total Accepted:    149.7K
 * Total Submissions: 348.8K
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
 * 
 * 求在该柱状图中，能够勾勒出来的矩形的最大面积。
 * 
 * 
 * 
 * 
 * 
 * 以上是柱状图的示例，其中每个柱子的宽度为 1，给定的高度为 [2,1,5,6,2,3]。
 * 
 * 
 * 
 * 
 * 
 * 图中阴影部分为所能勾勒出的最大矩形面积，其面积为 10 个单位。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入: [2,1,5,6,2,3]
 * 输出: 10
 * 
 */

// @lc code=start
class Solution {
      public:
	int largestRectangleArea(vector<int> &heights) {
		int maxs = 0;
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        stack<int> stk; // An ascending stack.
        stk.push(0);
        for (int i = 0; i < heights.size(); i++) {
            while (!stk.empty() && heights[i] < heights[stk.top()]) {
                int top = stk.top();
                stk.pop();
                if (stk.empty()) {
                    maxs = max(maxs, heights[top]);
                    break;
                }
                int left = stk.top();
                int width =  i - left - 1;
                int hi = heights[top];
                maxs = max(hi * width, maxs);
            }
            stk.push(i);
        }
        return maxs;
	}
};
// @lc code=end

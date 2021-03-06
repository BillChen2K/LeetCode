#include "header.h"
/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 *
 * https://leetcode-cn.com/problems/permutations/description/
 *
 * algorithms
 * Medium (77.83%)
 * Likes:    1272
 * Dislikes: 0
 * Total Accepted:    293.2K
 * Total Submissions: 376.8K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个 没有重复 数字的序列，返回其所有可能的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,2,3]
 * 输出:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 */

// @lc code=start
class Solution {
      private:
	vector<vector<int>> ans;

	void permute(vector<int> &nums, int len) {
		if (len == nums.size()) {
			ans.push_back(nums);
			return;
		}
		for (int i = len; i < nums.size(); i++) {
			swap(nums[i], nums[len]);
			permute(nums, len + 1);
			swap(nums[i], nums[len]);
		}
	}

      public:
	vector<vector<int>> permute(vector<int> &nums) {
		permute(nums, 0);
		return ans;
	}
};
// @lc code=end
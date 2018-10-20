// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
//
// Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
//
// Example 1:
//
//
// Input: [2,3,2]
// Output: 3
// Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
//              because they are adjacent houses.
//
//
// Example 2:
//
//
// Input: [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
//              Total amount you can rob = 1 + 3 = 4.
//


class Solution {
public:
    //1，2，3，4，5，6，7
    //1，2，3，4，5，6
    //
    int rob(vector<int>& nums) {
        if (nums.size() <= 1) return nums.empty() ? 0 : nums[0];
        //从0开始抢，排除尾巴。从1开始抢，可以算上尾巴，因为尾巴和头不会触碰
        return max(rob(nums, 0, nums.size() - 1), rob(nums, 1, nums.size()));
    }
    int rob(vector<int> &nums, int left, int right) {
        int a = 0, b = 0;
        for (int i = left; i < right; ++i) {
            int m = a, n = b;//a代表之前dp[i-2]，b是dp[i-1]
            a = n + nums[i];
            b = max(m, n);//b是dp[i]
        }
        return max(a, b);
    }
};

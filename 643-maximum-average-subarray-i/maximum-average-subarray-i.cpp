//
// Given an array consisting of n integers, find the contiguous subarray of given length k that has the maximum average value. And you need to output the maximum average value.
//
//
// Example 1:
//
// Input: [1,12,-5,-6,50,3], k = 4
// Output: 12.75
// Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75
//
//
//
// Note:
//
// 1 <= k <= n <= 30,000.
// Elements of the given array will be in the range [-10,000, 10,000].
//
//


class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        //典型的动态规划题，先计算前4个平均数，然后循环后移，如果平均数大于dp，则取代之
        //并记录游标
         double sum = accumulate(nums.begin(), nums.begin() + k, 0), res = sum;
        for (int i = k; i < nums.size(); ++i) {
            sum += nums[i] - nums[i - k];
            res = max(res, sum);
        }
        return res / k;
    }
};

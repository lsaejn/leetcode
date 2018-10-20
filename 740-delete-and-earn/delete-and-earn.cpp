//
// Given an array nums of integers, you can perform operations on the array.
//
// In each operation, you pick any nums[i] and delete it to earn nums[i] points.  After, you must delete every element equal to nums[i] - 1 or nums[i] + 1.
//
// You start with 0 points.  Return the maximum number of points you can earn by applying such operations.
//
//
// Example 1:
//
// Input: nums = [3, 4, 2]
// Output: 6
// Explanation: 
// Delete 4 to earn 4 points, consequently 3 is also deleted.
// Then, delete 2 to earn 2 points. 6 total points are earned.
//
//
//
// Example 2:
//
// Input: nums = [2, 2, 3, 3, 3, 4]
// Output: 9
// Explanation: 
// Delete 3 to earn 3 points, deleting both 2's and the 4.
// Then, delete 3 again to earn 3 points, and 3 again to earn 3 points.
// 9 total points are earned.
//
//
//
// Note:
// The length of nums is at most 20000.
// Each element nums[i] is an integer in the range [1, 10000].
//


class Solution {
public:
    //我们先设想一下，可以排序，然后统计每个元素出现的个数
    //如果拿本数字，当前的积分就是不拿前面的数字的积分加上当前数字之和
    //如果我们不拿当前的数字，那么对于前面的数字我们既可以拿也可以不拿
    int deleteAndEarn(vector<int>& nums) {
        vector<int> sums(10001, 0);
        int take = 0, skip = 0;
        for (int num : nums) 
            sums[num] += num;
        for (int i = 0; i < 10001; ++i)
        {
            int takei = skip + sums[i];
            int skipi = max(skip, take);
            take = takei; 
            skip = skipi;
        }
        return max(skip, take); 
    }
};

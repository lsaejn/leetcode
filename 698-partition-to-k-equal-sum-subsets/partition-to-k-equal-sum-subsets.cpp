// Given an array of integers nums and a positive integer k, find whether it's possible to divide this array into k non-empty subsets whose sums are all equal.
//
// Example 1:
//
// Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
// Output: True
// Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
//
//
//
// Note:
// 1 <= k <= len(nums) <= 16.
// 0 < nums[i] < 10000.
//


class Solution {
public:
    //这种写法首先不太简明，其本质就是对于每个元素，分别求和
    //4---->7,6,7,9,6,5
    //
    bool canPartitionKSubsets(vector<int>& nums, int k)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) 
            return false;
        vector<bool> visited(nums.size(), false);
        return helper(nums, k, sum / k, 0, 0, visited);
    }
    //找到了继续从0开始
    bool helper(vector<int>& nums, int k, int target, int start, int curSum, vector<bool>& visited) {
        if(curSum>target) return false;
        if (k == 1) 
            return true;
        if (curSum == target) 
            return helper(nums, k - 1, target, 0, 0, visited);
        for (int i = start; i < nums.size(); ++i)
        {
            if (visited[i]) 
                continue;
            visited[i] = true;
            //为什么是i+1呢？是为了避免重复32** 33** 35**
            if (helper(nums, k, target, i + 1, curSum + nums[i], visited)) 
                return true;
            visited[i] = false;
        }
        return false;
    }
};

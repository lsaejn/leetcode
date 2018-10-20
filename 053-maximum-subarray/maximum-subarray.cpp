// Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
//
// Example:
//
//
// Input: [-2,1,-3,4,-1,2,1,-5,4],
// Output: 6
// Explanation: [4,-1,2,1] has the largest sum = 6.
//
//
// Follow up:
//
// If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
//


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //明显的动态规划,因为是连续的，所以这个子序列：1.取前面和后面的元素则和变小，
        //比如，如果4，左边的dp(取该元素)是依次[-2，1,-2，4,3,5,6,1,5][]
        if(nums.empty()) return 0;
        vector<int> vec;
        vec.push_back(nums[0]);
        for(int i=1;i!=nums.size();++i)
        {
            if(vec.back()<0)
                vec.push_back(nums[i]);
            else
                vec.push_back(nums[i]+vec.back());            
        }
        int max=INT32_MIN;
        for(int i=0;i!=vec.size();++i)
        {
            if (vec[i]>max)
                max=vec[i];
        }
        return max;
    }
};

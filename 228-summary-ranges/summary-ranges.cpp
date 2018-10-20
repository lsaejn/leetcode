// Given a sorted integer array without duplicates, return the summary of its ranges.
//
// Example 1:
//
//
// Input:  [0,1,2,4,5,7]
// Output: ["0->2","4->5","7"]
// Explanation: 0,1,2 form a continuous range; 4,5 form a continuous range.
//
//
// Example 2:
//
//
// Input:  [0,2,3,4,6,8,9]
// Output: ["0","2->4","6","8->9"]
// Explanation: 2,3,4 form a continuous range; 8,9 form a continuous range.
//
//


class Solution {
public:
    //这个太容易。。。
    vector<string> summaryRanges(vector<int>& nums)
    {
        vector<string> res;
        int i = 0, n = nums.size();
        while (i < n) 
        {
            int j = 1;
            while (i + j < n && nums[i + j] - nums[i] == j)
                ++j;
            res.push_back(j <= 1 ? to_string(nums[i]) : to_string(nums[i]) + "->" + to_string(nums[i + j - 1]));
            i += j;
        }
        return res;
    }
};

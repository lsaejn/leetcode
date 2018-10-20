// Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.
//
// Example: 
//
//
// Input: s = 7, nums = [2,3,1,2,4,3]
// Output: 2
// Explanation: the subarray [4,3] has the minimal length under the problem constraint.
//
// Follow up:
//
// If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n). 
//


class Solution {
public:
    //似乎是可以用滑动条窗口来解
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.empty()) return 0;
        if(accumulate(nums.begin(),nums.end(),0)<s) return 0;
        int minSize = INT32_MAX;
        int sum = 0;
        int count = 0;
        for (int i = 0; i != nums.size(); ++i)
        {
            sum = sum + nums[i];
            ++count;
            while (sum >= s)
            {
                minSize = min(count, minSize);
                sum -= nums[i - count + 1];
                --count;			
            }
        }
        return minSize;
    }
};

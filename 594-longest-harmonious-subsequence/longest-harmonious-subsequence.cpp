// We define a harmonious array is an array where the difference between its maximum value and its minimum value is exactly 1.
//
// Now, given an integer array, you need to find the length of its longest harmonious subsequence among all its possible subsequences.
//
// Example 1:
//
// Input: [1,3,2,2,5,2,3,7]
// Output: 5
// Explanation: The longest harmonious subsequence is [3,2,2,2,3].
//
//
//
// Note:
// The length of the input array will not exceed 20,000.
//
//
//


class Solution {
public:
    //和谐子序列就是序列中数组的最大最小差值均为1。
    //要求求出这个子序列的最长长度
    //我们似乎应该排序，找出最多的那个元素，然后前面后面两个元素择其一，但是11111-444555
    //所以我们选择从头遍历，如果本元素和之前元素的差<1,count++,大于1，count清零,count超过max,取代之。复杂度on
    int findLHS(vector<int>& nums)
    {
        int res = 0;
        map<int, int> m;
        for (int num : nums) 
            ++m[num];
        for (auto a : m) 
        {
            if (m.count(a.first + 1))
            {
                res = max(res, m[a.first] + m[a.first + 1]);
            }
        }
        return res;
    }
};

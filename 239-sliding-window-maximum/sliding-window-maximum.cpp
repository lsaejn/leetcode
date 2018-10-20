// Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.
//
// Example:
//
//
// Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
// Output: [3,3,5,5,6,7] 
// Explanation: 
//
// Window position                Max
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7
//
//
// Note: 
// You may assume k is always valid, 1 ≤ k ≤ input array's size for non-empty array.
//
// Follow up:
// Could you solve it in linear time?
//


class Solution {
public:
    //你应该这样思考，滑动窗口里，最大值的索引为index,那么它前面的索引都是没有意义的。
    //所以我们的队列保存一个索引序列，每个人都代表自己是后面序列的最大值
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for (int i=0; i<nums.size(); i++) 
        {
            if (!dq.empty() && dq.front() == i-k) //i-k是排满时应该删除的索引，pop
                dq.pop_front();
            while (!dq.empty() && nums[dq.back()] < nums[i])//本轮放入的元素比前面大，那么前面不可能有机会成为最大值，删除之
                dq.pop_back();
            dq.push_back(i);//放入
            if (i>=k-1) //从索引k-1开始才开始记录最大值
                ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};

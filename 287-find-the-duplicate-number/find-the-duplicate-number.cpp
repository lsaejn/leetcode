// Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.
//
// Example 1:
//
//
// Input: [1,3,4,2,2]
// Output: 2
//
//
// Example 2:
//
//
// Input: [3,1,3,4,2]
// Output: 3
//
// Note:
//
//
// 	You must not modify the array (assume the array is read only).
// 	You must use only constant, O(1) extra space.
// 	Your runtime complexity should be less than O(n2).
// 	There is only one duplicate number in the array, but it could be repeated more than once.
//
//


class Solution {
public:
    //这个数不止一次重复出现，我们可以再一次准备bitset<65535>，那个数必然落入我们的计数范围。
    //注意题目，复杂度小于n**2,所以暗示我们，对每个元素进行二分搜索
    //1，2，3，5，8，7，2，4，6.
    int findDuplicate(vector<int>& nums) {
        int low = 1, high = nums.size() - 1;
        while (low < high)
        {
            int mid = low + (high - low) * 0.5;
            int cnt = 0;
            for (auto a : nums) 
                if (a <= mid) 
                    ++cnt;
            if (cnt <= mid) 
                low = mid + 1;
            else high = mid;
        }
        return low;
    }
};

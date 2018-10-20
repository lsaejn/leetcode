// Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....
//
// Example 1:
//
//
// Input: nums = [1, 5, 1, 1, 6, 4]
// Output: One possible answer is [1, 4, 1, 5, 1, 6].
//
// Example 2:
//
//
// Input: nums = [1, 3, 2, 2, 3, 1]
// Output: One possible answer is [2, 3, 1, 3, 1, 2].
//
// Note:
// You may assume all input has valid answer.
//
// Follow Up:
// Can you do it in O(n) time and/or in-place with O(1) extra space?
//


class Solution {
public:
    //先给数组排序，然后在做调整。调整的方法是找到数组的中间的数，相当于把有序数组从中间分成两部分，然后从前半段的末尾取一个，在从后半的末尾去一个
    void wiggleSort(vector<int>& nums)
    {
        vector<int> tmp = nums;
        int n = nums.size(), k = (n + 1) / 2, j = n; 
        sort(tmp.begin(), tmp.end());
        for (int i = 0; i < n; ++i)
            nums[i] = i & 1 ? tmp[--j] : tmp[--k];
    }
};

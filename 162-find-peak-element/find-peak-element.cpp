// A peak element is an element that is greater than its neighbors.
//
// Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and return its index.
//
// The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
//
// You may imagine that nums[-1] = nums[n] = -∞.
//
// Example 1:
//
//
// Input: nums = [1,2,3,1]
// Output: 2
// Explanation: 3 is a peak element and your function should return the index number 2.
//
// Example 2:
//
//
// Input: nums = [1,2,1,3,5,6,4]
// Output: 1 or 5 
// Explanation: Your function can return either index number 1 where the peak element is 2, 
//              or index number 5 where the peak element is 6.
//
//
// Note:
//
// Your solution should be in logarithmic complexity.
//


class Solution {
public:
    //1，2，3，4，5，4，5，4，5，6，7，9，7，6，5，4，3，5，6，9，8
    //对数复杂度是什么意思呢？我们依次遍历，如果右侧比自己大，则前进之，无论如何也不可能对数复杂度
    //但是这道题有个强烈的条件，无重复，任意峰值，并且左右都是无穷小
    int findPeakElement(vector<int>& nums) {
        //因为最左和最右都是最小值，从0开始遍历，找到降序即可，从尾巴向左看，找到升序即可
        int left = 0, right = nums.size()-1;
        while (left <right) 
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[mid+1]) left = mid + 1;
            else right = mid;
        }
        return right;
    }
};

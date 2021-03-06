// Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
//
// Your algorithm's runtime complexity must be in the order of O(log n).
//
// If the target is not found in the array, return [-1, -1].
//
// Example 1:
//
//
// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
//
// Example 2:
//
//
// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]
//


class Solution {
public:
    //这道题一点不好的地方是，C++以开区间作为结束位置
    //1，2，3，4，5,5,5,5, 7, 7, 8, 8, 8,8,10，11，19
    vector<int> searchRange(vector<int>& nums, int target) //这个解法太精妙了，最重要的是作者对于二分查找已经炉火纯青
    {
        if(nums.size()==0) return {-1,-1};
        vector<int> res(2, -1);
        int left = 0, right = nums.size() - 1;
        while (left < right)//保证left<=target,
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        if (nums[left] != target) return res;//!!!!!!!!!!!!!!!!这是中点，如果没有值，left==right
        res[0] = left;
        right = nums.size();
        while (left < right) 
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) left = mid + 1;
            else right= mid;
        }
        res[1] = left - 1;
        return res;
    }
};

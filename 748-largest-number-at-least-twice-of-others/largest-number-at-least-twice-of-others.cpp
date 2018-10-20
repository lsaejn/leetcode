// In a given integer array nums, there is always exactly one largest element.
//
// Find whether the largest element in the array is at least twice as much as every other number in the array.
//
// If it is, return the index of the largest element, otherwise return -1.
//
// Example 1:
//
//
// Input: nums = [3, 6, 1, 0]
// Output: 1
// Explanation: 6 is the largest integer, and for every other number in the array x,
// 6 is more than twice as big as x.  The index of value 6 is 1, so we return 1.
//
//
//  
//
// Example 2:
//
//
// Input: nums = [1, 2, 3, 4]
// Output: -1
// Explanation: 4 isn't at least as big as twice the value of 3, so we return -1.
//
//
//  
//
// Note:
//
//
// 	nums will have a length in the range [1, 50].
// 	Every nums[i] will be an integer in the range [0, 99].
//
//
//  
//


class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        //我们首先需要假定每个数都大于0
        //我们只需要保证最大数比次大数的两倍大就行了
        int mx = INT_MIN, secondMx = INT_MIN, mxId = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] > mx) 
            {
                secondMx = mx;//最大数变成次大数
                mx = nums[i];
                mxId = i;
            } else if (nums[i] > secondMx) {
                secondMx = nums[i];
            }
        }
        return (mx - secondMx >= secondMx) ? mxId : -1;
    }
};

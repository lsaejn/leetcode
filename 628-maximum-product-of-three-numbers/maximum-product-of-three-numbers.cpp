// Given an integer array, find three numbers whose product is maximum and output the maximum product.
//
// Example 1:
//
// Input: [1,2,3]
// Output: 6
//
//
//
// Example 2:
//
// Input: [1,2,3,4]
// Output: 24
//
//
//
// Note:
//
// The length of the given array will be in range [3,104] and all elements are in the range [-1000, 1000].
// Multiplication of any three numbers in the input won't exceed the range of 32-bit signed integer.
//
//


class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        //
        //-5 -4 -3 0 3 4 5
        //1.模最大的是2个负数，然后是一个正数 -5*-4*5
        //2.模最大3负数 结果-5*-4*5
        //3.是1个负数3*4*5
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int p = nums[0] * nums[1] * nums[n - 1];
        return max(p, nums[n - 1] * nums[n - 2] * nums[n - 3]);
    }
};

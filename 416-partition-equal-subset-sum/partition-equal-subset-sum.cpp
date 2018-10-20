// Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.
//
//
// Note:
//
// Each of the array element will not exceed 100.
// The array size will not exceed 200.
//
//
//
// Example 1:
//
// Input: [1, 5, 11, 5]
//
// Output: true
//
// Explanation: The array can be partitioned as [1, 5, 5] and [11].
//
//
//
// Example 2:
//
// Input: [1, 2, 3, 5]
//
// Output: false
//
// Explanation: The array cannot be partitioned into equal sum subsets.
//
//


class Solution {
public:
    // 1,2,3,4, 7,8,9,10
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i =0;i<nums.size();i++){
            sum+= nums[i];
        }
        if(sum%2) return false;
        sum /= 2;//22
        sort(nums.rbegin(),nums.rend());//10,9,8,7,4,3,2,1
        return helper(nums, sum, 0);
    }
    bool helper(vector<int>& nums, int sum, int index){//看nums[index]是不是sum
        if(sum == nums[index]) return true;
        if(sum < nums[index]) return false;
        return helper(nums,sum-nums[index],index+1) || helper(nums,sum,index+1);//sum>nums[index],2个情况，减掉它，继续找，不减掉它，继续找
    }
};

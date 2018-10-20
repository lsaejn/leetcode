// Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
//
// Example:
//
//
// Input: [0,1,0,3,12]
// Output: [1,3,12,0,0]
//
// Note:
//
//
// 	You must do this in-place without making a copy of the array.
// 	Minimize the total number of operations.
//
//


class Solution {
public://110033004055500067 11300...
    void moveZeroes(vector<int>& nums) {
        //一个游标记录第一个0的位置，遍历，如果非0，交换，如果是0，数量加1
        int pos=-1;
        int count=0;
        for(int i=0;i!=nums.size();++i)
        {
            if(nums[i]==0&&count==0)
            {
                count++;
                pos=i;
            }
            else if(nums[i]==0&&count!=0)
                count++;
            else if(nums[i]!=0&&count!=0)
            {
                swap(nums[i],nums[pos]);
                pos++;
            }           
        }
    }
};

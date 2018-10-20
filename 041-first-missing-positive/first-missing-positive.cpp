// Given an unsorted integer array, find the smallest missing positive integer.
//
// Example 1:
//
//
// Input: [1,2,0]
// Output: 3
//
//
// Example 2:
//
//
// Input: [3,4,-1,1]
// Output: 2
//
//
// Example 3:
//
//
// Input: [7,8,9,11,12]
// Output: 1
//
//
// Note:
//
// Your algorithm should run in O(n) time and uses constant extra space.
//


class Solution {
public:
    //提示我们用常数量的空间，很显然，一个bit<32768>足以表示正数的范围0~32767，出现一个数字i，bit[i]
    //然后找到从bit[1]开始的，第一个为0的索引，索引即数字
    int firstMissingPositive(vector<int>& nums) {
        bitset<32768> myBit;
        for(int i=0;i!=nums.size();++i)
        {
            if(nums[i]>0)
                myBit[nums[i]]=1;
        }
        for(int i=1;i!=myBit.size();++i)
            if(myBit[i]==0)
                return i;
    }
};

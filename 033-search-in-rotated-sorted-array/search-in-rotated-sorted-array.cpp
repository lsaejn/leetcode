// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
// (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
//
// You are given a target value to search. If found in the array return its index, otherwise return -1.
//
// You may assume no duplicate exists in the array.
//
// Your algorithm's runtime complexity must be in the order of O(log n).
//
// Example 1:
//
//
// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
//
//
// Example 2:
//
//
// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1
//


class Solution {
public:
    //在位置i逆转，就是把i的右边转置，再转置整个数组
    int search(vector<int>& nums, int target) 
    {
        if(nums.empty()) return -1;
        //sort(nums.begin(),nums.end());
        
        int pos=-1;
        for(int i=0;i!=nums.size();++i)
        {
            if(nums[i]==target)
            {
                pos=i;
                break;
            }               
        }
        if(pos==-1) return pos;
      //  auto copy=nums;
      //  reverse(nums.begin(),nums.begin()+pos+1);
      //  reverse(nums.begin()+pos+1,nums.end());
      //  reverse(nums.begin(),nums.end());
      //  if(nums==copy)
            return pos;
      //  else return -1;
    }
};

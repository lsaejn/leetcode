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
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


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

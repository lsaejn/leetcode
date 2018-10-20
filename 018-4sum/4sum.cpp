// Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
//
// Note:
//
// The solution set must not contain duplicate quadruplets.
//
// Example:
//
//
// Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
//
// A solution set is:
// [
//   [-1,  0, 0, 1],
//   [-2, -1, 1, 2],
//   [-2,  0, 0, 2]
// ]
//
//


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size()<4) return {};
        //wow!!!
        //先排序，再遍历，对于每个元素，查找剩余元素里是不是存在3个数之和满足target1
        //内循环，看剩余元素里是不是存在2个数之和满足target2
        //内循环，看剩余元素里是不是存在1个数之和满足target3
        //这样是不是可行，先看一看target=10,[12345], 1,9
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        for(int i=0;i!=nums.size()-3;++i)
        {
            if(i-1>0&&nums[i]==nums[i-1]) continue;//j > i + 1
            for(int j=i+1;j!=nums.size();++j)
            {
                int m=j+1;
                int n=nums.size()-1;
                while(m<n)
                {
                    auto sum=nums[i]+nums[j]+nums[m]+nums[n];
                    if(sum==target)
                        result.push_back({nums[i],nums[j],nums[m],nums[n]});
                        //m++;n--; 不用break 也不用else,少写一行代码
                    if(sum<target) m++;
                    else n--;
                }
            }
        }
        sort(result.begin(),result.end());
        result.erase(unique(result.begin(),result.end()),result.end());
        return result;
    }//-4 -1 -1 0 1 2
};

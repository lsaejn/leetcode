// Given an array of integers, return indices of the two numbers such that they add up to a specific target.
//
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
//
// Example:
//
//
// Given nums = [2, 7, 11, 15], target = 9,
//
// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].
//
//
//  
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> num_map;
        for(int i=0;i!=nums.size();++i)
        {
            int& elem=nums[i];
            auto iter=num_map.find(target-elem);
            if(iter==num_map.end())
                num_map[elem]=i;
            else
                return vector<int>{num_map[target-elem],i};                                
        }
        static vector<int> empty{};
        return empty;
        
    }
};

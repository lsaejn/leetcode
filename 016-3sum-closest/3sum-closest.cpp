// Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
//
// Example:
//
//
// Given array nums = [-1, 2, 1, -4], and target = 1.
//
// The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        //我们需要：一个给定数，两个遍历数。那么就变成找两数之和的最值了
        //先排序
        long long result=INT32_MAX;
        sort(nums.begin(),nums.end());
        for(int i=0;i!=nums.size()-2;++i)
        {
            if(i>0&&nums[i]==nums[i-1]) continue;
            int new_target=target-nums[i];
            //int sub=INT32_MAX;
            int j=i+1,k=nums.size()-1;
            // -5 -4 1 2 4 5 8 9   15
            while(j<k)
            {
				if (abs(nums[j] + nums[k] + nums[i] - target)<abs(result - target))
					result = nums[j] + nums[k] + nums[i];
				if (nums[j] + nums[k]+ nums[i]>target) k--;
				else if (nums[j] + nums[k]+ nums[i]<target) j++;
				else return nums[j] + nums[k] + nums[i];
            }
            
        }
        return result;
        //-5 -4 -3 -2 -1 3
        //-3 0 1 2
    }
};

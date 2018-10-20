// Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
//
// Note:
//
// The solution set must not contain duplicate triplets.
//
// Example:
//
//
// Given array nums = [-1, 0, 1, 2, -1, -4],
//
// A solution set is:
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //用递归做超出时间限制
    //太难了。只能求出所有a+b的组合，看是不是有c=-(a+b)
    //可能的优化：正负数的数量，求和的时候选择较少的那组。反正是on**2，排个序也没什么。。
    //这个解更好
    //排序可以避免查找重复的值
    //然后依次遍历，相当于在一个区间里找两个数的和=num
    //-5，-4，-3，-2，-2，-1  0 2 3 4
	vector<vector<int>> threeSum(vector<int>& nums)
	{
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int k = 0; k < nums.size(); ++k)
        {
            if (nums[k] > 0) //因为我们从小（左边）遍历，所以求出负数那部分结果。
                break;
            if (k > 0 && nums[k] == nums[k - 1]) 
                continue;
            int target = 0 - nums[k];
            int i = k + 1, j = nums.size() - 1;
            while (i < j) 
            {
                if (nums[i] + nums[j] == target) 
                {
                    res.push_back({nums[k], nums[i], nums[j]});
                    while (i < j && nums[i] == nums[i + 1]) ++i;
                    while (i < j && nums[j] == nums[j - 1]) --j;
                    ++i; --j;
                } 
                else if (nums[i] + nums[j] < target) ++i;
                else --j;
            }
        }
        return res;
	}
};

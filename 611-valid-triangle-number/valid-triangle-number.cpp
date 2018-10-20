// Given an array consists of non-negative integers,  your task is to count the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.
//
// Example 1:
//
// Input: [2,2,3,4]
// Output: 3
// Explanation:
// Valid combinations are: 
// 2,3,4 (using the first 2)
// 2,3,4 (using the second 2)
// 2,2,3
//
//
//
// Note:
//
// The length of the given array won't exceed 1000.
// The integers in the given array are in the range of [0, 1000].
//
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    ////海伦公式 √[s(s-a)(s-b)(s-c)]，其中s=(a+b+c)/2
    //直接暴力就通过了
    int triangleNumber(vector<int>& nums) {
        //sort(nums.begin(),nums.end());
        int result=0;
        for(int i=0;i!=nums.size();++i)
            for(int j=i+1;j!=nums.size();++j)
                for(int k=j+1;k!=nums.size();++k)
                {
                    double s = nums[i] + nums[j] + nums[k];
                    s = s*0.5;
                    if ((s-nums[i])*(s-nums[j])*(s-nums[k])>0)
                        result++;
                }
        return result;
    }
};

//
// The set S originally contains numbers from 1 to n. But unfortunately, due to the data error, one of the numbers in the set got duplicated to another number in the set, which results in repetition of one number and loss of another number. 
//
//
//
// Given an array nums representing the data status of this set after the error. Your task is to firstly find the number occurs twice and then find the number that is missing. Return them in the form of an array.
//
//
//
// Example 1:
//
// Input: nums = [1,2,2,4]
// Output: [2,3]
//
//
//
// Note:
//
// The given array size will in the range [2, 10000].
// The given array's numbers won't have any order.
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //题目看错了。。fuck
    vector<int> findErrorNums(vector<int>& nums) {
        //思路是这样，每个数字一位，所以要一个20000bit的数组
        bitset<20001> col;
        int twice;
        for(int i=0;i!=nums.size();++i)
        {
            if (col[nums[i]]==0)
                col[nums[i]]=1;
            else
            {
                twice=nums[i];
                col[nums[i]]=1;
            }            
        }
        for(int i=1;i!=col.size();++i)
            if(col[i]==0)
                return {twice,i};
    }
};

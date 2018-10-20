// Given a non-empty array of integers, every element appears twice except for one. Find that single one.
//
// Note:
//
// Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
//
// Example 1:
//
//
// Input: [2,2,1]
// Output: 1
//
//
// Example 2:
//
//
// Input: [4,1,2,1,2]
// Output: 4
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result=nums[0];
        for(int i=1;i!=nums.size();++i){
            result ^= nums[i];
        
        }
        return result;
        /*最开始是想到水王那个，但是没有辅助空间走不通，相同抵消，很快便想到位运算，写一个式子，差不多就得到结果了
            012342310
            00000000
            00000001
            00000010
            00000011
            00000100        
        */        
    }
};

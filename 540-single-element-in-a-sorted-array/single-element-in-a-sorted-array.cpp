//
// Given a sorted array consisting of only integers where every element appears twice except for one element which appears once. Find this single element that appears only once. 
//
//
// Example 1:
//
// Input: [1,1,2,3,3,4,4,8,8]
// Output: 2
//
//
//
// Example 2:
//
// Input: [3,3,7,7,10,11,11]
// Output: 10
//
//
//
// Note:
// Your solution should run in O(log n) time and O(1) space.
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //我们看看异或是不是有用001 001 011 011 100 100 101 101 111
    int singleNonDuplicate(vector<int>& nums) {
        //if(nums.empty()) return 0;
        int i=nums[0];
        for(int j=1;j!=nums.size();++j)
        {
            i=i^nums[j];
        }
        return i;
    }
};

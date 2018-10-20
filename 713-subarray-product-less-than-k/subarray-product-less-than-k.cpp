// Your are given an array of positive integers nums.
// Count and print the number of (contiguous) subarrays where the product of all the elements in the subarray is less than k.
//
// Example 1:
//
// Input: nums = [10, 5, 2, 6], k = 100
// Output: 8
// Explanation: The 8 subarrays that have product less than 100 are: [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6].
// Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.
//
//
//
// Note:
// 0 < nums.length <= 50000.
// 0 < nums[i] < 1000.
// 0 <= k < 10^6.
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //滑动窗口维持一个小于k的窗口，向右移动，超出k则减掉左边
    /*
    for window (5, 2), when 6 is introduced, it add 3 new subarray: (5, (2, (6)))
        (6)
     (2, 6)
  (5, 2, 6)
  
  10,5,2,6
  增加的过程:
  +10----10
  +5-----5,{10,5}
  +2-----
  -10-----{2},{5,2}
  +6-----{5,2,6},{2,6} {6}
*/
    //思考过程:要求连续，很强烈的条件。
    //我们从头开始乘，添加2之后变成10*5*2,没办法继续了，10必须剔除
    //关键是剔除之后，增加了多少。
    int numSubarrayProductLessThanK(vector<int>& nums, int k)
    {
        if (k == 0) 
            return 0;
        int cnt = 0;
        int pro = 1;
        for (int i = 0, j = 0; j < nums.size(); j++) 
        {
            pro *= nums[j];
            while (i <= j && pro >= k) 
                pro /= nums[i++];
            
            cnt += j - i + 1;
        }
        return cnt;
    }
};

//
// Given a sequence of n integers a1, a2, ..., an, a 132 pattern is a subsequence ai, aj, ak such
// that i < j < k and ai < ak < aj. Design an algorithm that takes a list of n numbers as input and checks whether there is a 132 pattern in the list.
//
// Note: n will be less than 15,000.
//
// Example 1:
//
// Input: [1, 2, 3, 4]
//
// Output: False
//
// Explanation: There is no 132 pattern in the sequence.
//
//
//
// Example 2:
//
// Input: [3, 1, 4, 2]
//
// Output: True
//
// Explanation: There is a 132 pattern in the sequence: [1, 4, 2].
//
//
//
// Example 3:
//
// Input: [-1, 3, 2, 0]
//
// Output: True
//
// Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int third = INT_MIN;
        stack<int> s;
        for (int i = nums.size() - 1; i >= 0; --i) 
        {
            if (nums[i] < third) return true;
            else 
                while (!s.empty() && nums[i] > s.top())
            {
                third = s.top(); 
                s.pop();
            }
            s.push(nums[i]);
        }
        return false;  
    }
};

// Given an array nums and a value val, remove all instances of that value in-place and return the new length.
//
// Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
//
// The order of elements can be changed. It doesn't matter what you leave beyond the new length.
//
// Example 1:
//
//
// Given nums = [3,2,2,3], val = 3,
//
// Your function should return length = 2, with the first two elements of nums being 2.
//
// It doesn't matter what you leave beyond the returned length.
//
//
// Example 2:
//
//
// Given nums = [0,1,2,2,3,0,4,2], val = 2,
//
// Your function should return length = 5, with the first five elements of nums containing 0, 1, 3, 0, and 4.
//
// Note that the order of those five elements can be arbitrary.
//
// It doesn't matter what values are set beyond the returned length.
//
// Clarification:
//
// Confused why the returned value is an integer but your answer is an array?
//
// Note that the input array is passed in by reference, which means modification to the input array will be known to the caller as well.
//
// Internally you can think of this:
//
//
// // nums is passed in by reference. (i.e., without making a copy)
// int len = removeElement(nums, val);
//
// // any modification to nums in your function would be known by the caller.
// // using the length returned by your function, it prints the first len elements.
// for (int i = 0; i < len; i++) {
//     print(nums[i]);
// }
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


#include <algorithm>
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {//直接用了算法库，因为都很直观
        sort(nums.begin(),nums.end());
        int count=std::count(nums.begin(),nums.end(),val);
        //nums.erase(find(nums.begin(),nums.end(),val),find(nums.begin(),nums.end(),val)+count);
        remove(nums.begin(),nums.end(),val);
        return nums.size()-count;
        
    }
};

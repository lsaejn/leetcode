//
// You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements are subset of nums2. Find all the next greater numbers for nums1's elements in the corresponding places of nums2. 
//
//
//
// The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. If it does not exist, output -1 for this number.
//
//
// Example 1:
//
// Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
// Output: [-1,3,-1]
// Explanation:
//     For number 4 in the first array, you cannot find the next greater number for it in the second array, so output -1.
//     For number 1 in the first array, the next greater number for it in the second array is 3.
//     For number 2 in the first array, there is no next greater number for it in the second array, so output -1.
//
//
//
// Example 2:
//
// Input: nums1 = [2,4], nums2 = [1,2,3,4].
// Output: [3,-1]
// Explanation:
//     For number 2 in the first array, the next greater number for it in the second array is 3.
//     For number 4 in the first array, there is no next greater number for it in the second array, so output -1.
//
//
//
//
// Note:
//
// All elements in nums1 and nums2 are unique.
// The length of both nums1 and nums2 would not exceed 1000.
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        
        //遍历一次右边，把每个值的右大值求处来，放到哈希表里
        //遍历左边，依次查表即可On复杂度 On辅助空间
        vector<int> res(findNums.size());
                
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) 
            m[nums[i]] = i;

        for (int i = 0; i < findNums.size(); ++i)
        {
            res[i] = -1;
            int start = m[findNums[i]];
            for (int j = start + 1; j < nums.size(); ++j) 
            {
                if (nums[j] > findNums[i])
                {
                    res[i] = nums[j];
                    break;
                }
            }
        }
        return res;
    }
};

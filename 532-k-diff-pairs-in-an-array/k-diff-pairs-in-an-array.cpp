//
// Given an array of integers and an integer k, you need to find the number of unique k-diff pairs in the array. Here a k-diff pair is defined as an integer pair (i, j), where i and j are both numbers in the array and their absolute difference is k.
//
//
//
// Example 1:
//
// Input: [3, 1, 4, 1, 5], k = 2
// Output: 2
// Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).Although we have two 1s in the input, we should only return the number of unique pairs.
//
//
//
// Example 2:
//
// Input:[1, 2, 3, 4, 5], k = 1
// Output: 4
// Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).
//
//
//
// Example 3:
//
// Input: [1, 3, 1, 5, 4], k = 0
// Output: 1
// Explanation: There is one 0-diff pair in the array, (1, 1).
//
//
//
// Note:
//
// The pairs (i, j) and (j, i) count as the same pair.
// The length of the array won't exceed 10,000.
// All the integers in the given input belong to the range: [-1e7, 1e7].
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //[1,3] [3,5]距离之差都是2
    //k=4 1,3,1,3,1,2,2,2,2,2->1:3,3:2,2:5,
    
    //注意，是unique pairs
    int findPairs(vector<int>& nums, int k) {
        //哈希表，一边放一边找
        int res = 0;
        int n = nums.size();
        unordered_map<int, int> m;//保存数字和个数
        for (int num : nums) 
            ++m[num];
        for (auto a : m) 
        {
            if (k == 0 && a.second > 1) ++res;//k=0，比如[2，2]
            if (k > 0 && m.count(a.first + k)) //比如2，1找3，3找5
                ++res;
        }
        return res;
    }
};

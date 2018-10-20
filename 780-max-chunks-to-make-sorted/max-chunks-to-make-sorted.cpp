// Given an array arr that is a permutation of [0, 1, ..., arr.length - 1], we split the array into some number of "chunks" (partitions), and individually sort each chunk.  After concatenating them, the result equals the sorted array.
//
// What is the most number of chunks we could have made?
//
// Example 1:
//
//
// Input: arr = [4,3,2,1,0]
// Output: 1
// Explanation:
// Splitting into two or more chunks will not return the required result.
// For example, splitting into [4, 3], [2, 1, 0] will result in [3, 4, 0, 1, 2], which isn't sorted.
//
//
// Example 2:
//
//
// Input: arr = [1,0,2,3,4]
// Output: 4
// Explanation:
// We can split into two chunks, such as [1, 0], [2, 3, 4].
// However, splitting into [1, 0], [2], [3], [4] is the highest number of chunks possible.
//
//
// Note:
//
//
// 	arr will have length in range [1, 10].
// 	arr[i] will be a permutation of [0, 1, ..., arr.length - 1].
//
//
//  " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
//基于范围的搜索
    int maxChunksToSorted(vector<int>& arr) {
        int range=arr[0];
        int count=1;
        for(int i=0;i!=arr.size();++i)
        {
            if(i<=range)
                if(arr[i]>range)
                    range=arr[i];
            if(i>range)
            {
                count++;
                range=arr[i];
            }
        }
        return count;
    }
};

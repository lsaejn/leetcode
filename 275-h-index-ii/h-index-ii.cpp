// Given an array of citations sorted in ascending order (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.
//
// According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."
//
// Example:
//
//
// Input: citations = [0,1,3,5,6]
// Output: 3 
// Explanation: [0,1,3,5,6] means the researcher has 5 papers in total and each of them had 
//              received 0, 1, 3, 5, 6 citations respectively. 
//              Since the researcher has 3 papers with at least 3 citations each and the remaining 
//              two with no more than 3 citations each, her h-index is 3.
//
// Note:
//
// If there are several possible values for h, the maximum one is taken as the h-index.
//
// Follow up:
//
//
// 	This is a follow up problem to H-Index, where citations is now guaranteed to be sorted in ascending order.
// 	Could you solve it in logarithmic time complexity?
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //已经排好序了
    //1，reverse，然后调用之前的算法。
    //2.二分查找。
    //总之我们的目的是让i>=citations[i],返回i即可。因为对于已排序的数组，i>=citations[i]意味着第
    int hIndex(vector<int>& citations) {
        int len = citations.size(), left = 0, right = len - 1;
        while (left <= right) {
            int mid = 0.5 * (left + right);
            if (citations[mid] == len - mid) return len - mid;
            else if (citations[mid] > len - mid) right = mid - 1;
            else left = mid + 1;
        }
        return len - left;
    }
};

// A string S of lowercase letters is given.  Then, we may make any number of moves.
//
// In each move, we choose one of the first K letters (starting from the left), remove it, and place it at the end of the string.
//
// Return the lexicographically smallest string we could have after any number of moves.
//
//  
//
//
// Example 1:
//
//
// Input: S = "cba", K = 1
// Output: "acb"
// Explanation: 
// In the first move, we move the 1st character ("c") to the end, obtaining the string "bac".
// In the second move, we move the 1st character ("b") to the end, obtaining the final result "acb".
//
//
//
// Example 2:
//
//
// Input: S = "baaca", K = 3
// Output: "aaabc"
// Explanation: 
// In the first move, we move the 1st character ("b") to the end, obtaining the string "aacab".
// In the second move, we move the 3rd character ("c") to the end, obtaining the final result "aaabc".
//
//
//  
//
// Note:
//
//
// 	1 <= K <= S.length <= 1000
// 	S consists of lowercase letters only.
//
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //K>1时冒泡排序，结果是有序的
    //K==1时，我们看看efcda->{fcdae,cdaef,daefc,aefcd,efcda}
    //
    string orderlyQueue(string S, int K) {
        if (K > 1)
        {
            sort(S.begin(), S.end());
            return S;
        }
        string res = S;
        for (int i = 1; i < S.length(); i++)
            res = min(res, S.substr(i) + S.substr(0, i));
        return res;
    }
};

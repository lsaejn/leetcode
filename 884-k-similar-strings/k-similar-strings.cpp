// Strings A and B are K-similar (for some non-negative integer K) if we can swap the positions of two letters in A exactly K times so that the resulting string equals B.
//
// Given two anagrams A and B, return the smallest K for which A and B are K-similar.
//
// Example 1:
//
//
// Input: A = "ab", B = "ba"
// Output: 1
//
//
//
// Example 2:
//
//
// Input: A = "abc", B = "bca"
// Output: 2
//
//
//
// Example 3:
//
//
// Input: A = "abac", B = "baca"
// Output: 2
//
//
//
// Example 4:
//
//
// Input: A = "aabc", B = "abca"
// Output: 2
//
//
//
//
// Note:
//
//
// 	1 <= A.length == B.length <= 20
// 	A and B contain only lowercase letters from the set {'a', 'b', 'c', 'd', 'e', 'f'}
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    int kSimilarity(string A, string B) {
      for (int i=0; i<A.size(); i++)
      {
        if (A[i]==B[i])
            continue;
        vector<int> matches;
        for (int j=i+1;j<A.size();j++)
        { 
          if (A[j]==B[i] && A[j]!=B[j])//A[j]==B[j],我们打乱了一个本在位置上的元素
          {
            matches.push_back(j);
            if (A[i]==B[j])
            {
              swap(A[i],A[j]);
              return 1+kSimilarity(A.substr(i+1),B.substr(i+1));
            }
          }
        }
        int best=A.size()-1;
        for (int j: matches)
        {
            swap(A[i],A[j]);
            best = min(best, 1+kSimilarity(A.substr(i+1),B.substr(i+1)));
            swap(A[i],A[j]);
        }
        return best;
      }
      return 0;
    }
};

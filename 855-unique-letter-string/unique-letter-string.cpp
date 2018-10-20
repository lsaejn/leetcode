// A character is unique in string S if it occurs exactly once in it.
//
// For example, in string S = "LETTER", the only unique characters are "L" and "R".
//
// Let's define UNIQ(S) as the number of unique characters in string S.
//
// For example, UNIQ("LETTER") =  2.
//
// Given a string S, calculate the sum of UNIQ(substring) over all non-empty substrings of S.
//
// If there are two or more equal substrings at different positions in S, we consider them different.
//
// Since the answer can be very large, retrun the answer modulo 10 ^ 9 + 7.
//
//  
//
// Example 1:
//
//
// Input: "ABC"
// Output: 10
// Explanation: All possible substrings are: "A","B","C","AB","BC" and "ABC".
// Evey substring is composed with only unique letters.
// Sum of lengths of all substring is 1 + 1 + 1 + 2 + 2 + 3 = 10
//
// Example 2:
//
//
// Input: "ABA"
// Output: 8
// Explanation: The same as example 1, except uni("ABA") = 1.
//
//
//  
//
// Note: 0 <= S.length <= 10000.


class Solution {
public:
    //你觉得自己很牛？看到这个解法的时候，你一定是崩溃的。这不是代码的问题了，而是思考方式的碾压。
    int uniqueLetterString(string S) {
        int index[26][2], res = 0, N = S.length(), mod = pow(10, 9) + 7;
        memset(index, -1, sizeof(int) * 52);
        for (int i = 0; i < N; ++i) {
            int c = S[i] - 'A';
            res = (res + (i - index[c][1]) * (index[c][1] - index[c][0]) % mod) % mod;
            index[c][0] = index[c][1];
            index[c][1] = i;
        }
        for (int c = 0; c < 26; ++c)
            res = (res + (N - index[c][1]) * (index[c][1] - index[c][0]) % mod) % mod;
        return res;
    }
};  

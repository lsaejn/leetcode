// Given a string that consists of only uppercase English letters, you can replace any letter in the string with another letter at most k times. Find the length of a longest substring containing all repeating letters you can get after performing the above operations.
//
// Note:
// Both the string's length and k will not exceed 104.
//
//
//
// Example 1:
//
// Input:
// s = "ABAB", k = 2
//
// Output:
// 4
//
// Explanation:
// Replace the two 'A's with two 'B's or vice versa.
//
//
//
//
// Example 2:
//
// Input:
// s = "AABABBA", k = 1
//
// Output:
// 4
//
// Explanation:
// Replace the one 'A' in the middle with 'B' and form "AABBBBA".
// The substring "BBBB" has the longest repeating letters, which is 4.
//
//


class Solution {
public:
    int characterReplacement(string s, int k) {
/*
滑动窗口初始化为0，然后我们遍历字符串，
每次累加出现字符的个数，然后更新出现最多字符的个数，
然后我们判断当前滑动窗口是否满足之前说的那个条件，
如果不满足，我们就把滑动窗口左边界向右移动一个，
并注意去掉的字符要在counts里减一，直到满足条件，我们更新结果res即可
*/
        int res = 0, maxCnt = 0, start = 0;
        vector<int> counts(26, 0);
        for (int i = 0; i < s.size(); ++i) 
        {
            maxCnt = max(maxCnt, ++counts[s[i] - 'A']);
            while (i - start + 1 - maxCnt > k) //不相同个数>k了
            {
                --counts[s[start] - 'A'];
                ++start;
            }
            res = max(res, i - start + 1);
        }
        return res;     
    }
};

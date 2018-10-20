// Given a list of words, we may encode it by writing a reference string S and a list of indexes A.
//
// For example, if the list of words is ["time", "me", "bell"], we can write it as S = "time#bell#" and indexes = [0, 2, 5].
//
// Then for each index, we will recover the word by reading from the reference string from that index until we reach a "#" character.
//
// What is the length of the shortest reference string S possible that encodes the given words?
//
// Example:
//
//
// Input: words = ["time", "me", "bell"]
// Output: 10
// Explanation: S = "time#bell#" and indexes = [0, 2, 5].
//
//
// Note:
//
//
// 	1 <= words.length <= 2000.
// 	1 <= words[i].length <= 7.
// 	Each word has only lowercase letters.
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //因为index不唯一，所以这道题目不好确定index
    int minimumLengthEncoding(vector<string>& words)
    {
        unordered_set<string> s(words.begin(), words.end());
        for (string w : s)//相当暴力
            for (int i = 1; i < w.size(); ++i)
                s.erase(w.substr(i));//删除所有字串，比如time,删除ime/me/e
        int res = 0;
        for (string w : s) 
            res += w.size() + 1;
        return res;
    }
};

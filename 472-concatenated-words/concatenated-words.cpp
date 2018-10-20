// Given a list of words (without duplicates), please write a program that returns all concatenated words in the given list of words.
// A concatenated word is defined as a string that is comprised entirely of at least two shorter words in the given array.
//
// Example:
//
// Input: ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
//
// Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]
//
// Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats";  "dogcatsdog" can be concatenated by "dog", "cats" and "dog"; "ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".
//
//
//
// Note:
//
// The number of elements of the given array will not exceed 10,000 
// The length sum of elements in the given array will not exceed 600,000. 
// All the input string will only include lower case letters.
// The returned elements order does not matter. 
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution
{
    //这个方法居然通过了，可见。。。测试用例有问题。。
    vector<string> results;
    unordered_set<string> dict;
    int min_len = 1;
    bool isConcatenated(string const & word)
    {
        if (dict.count(word)) return true;
        for (int i =  min_len; i < word.size() - min_len + 1 ; ++ i)
            if (dict.count(word.substr(0, i)) > 0 && isConcatenated(word.substr(i, word.size() - i)))
                return true;
        return false;
    }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words)
    {
        sort(words.begin(), words.end(), [](const string &lhs, const string &rhs){return lhs.size() < rhs.size();});
        min_len = max(1ul, words.front().size());
        for (int i = 0; i < words.size();++i)
        {
            if (words[i].size() >= min_len * 2 && isConcatenated(words[i]))
                results.push_back(words[i]);
            dict.insert(words[i]);
        }
        return results;
    }
};

//
// Given many words, words[i] has weight i.
//
// Design a class WordFilter that supports one function, WordFilter.f(String prefix, String suffix).
// It will return the word with given prefix and suffix with maximum weight.  If no word exists, return -1.
//
//
// Examples:
//
// Input:
// WordFilter(["apple"])
// WordFilter.f("a", "e") // returns 0
// WordFilter.f("b", "") // returns -1
//
//
// Note:
//
// words has length in range [1, 15000].
// For each test case, up to words.length queries WordFilter.f may be made.
// words[i] has length in range [1, 10].
// prefix, suffix have lengths in range [0, 10].
// words[i] and prefix, suffix queries consist of lowercase letters only.
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class WordFilter {
public:
    WordFilter(vector<string> words)
    {
        for (int k = 0; k < words.size(); ++k)
        {
            for (int i = 0; i <= words[k].size(); ++i) 
            {
                for (int j = 0; j <= words[k].size(); ++j)
                {
                    m[words[k].substr(0, i) + "#" + words[k].substr(words[k].size() - j)] = k;
                }
            }
        }
    }

    int f(string prefix, string suffix)
    {
        return (m.count(prefix + "#" + suffix)) ? m[prefix + "#" + suffix] : -1;
    }

private:
    unordered_map<string, int> m;
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter obj = new WordFilter(words);
 * int param_1 = obj.f(prefix,suffix);
 */

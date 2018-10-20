// You have a list of words and a pattern, and you want to know which words in words matches the pattern.
//
// A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.
//
// (Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.)
//
// Return a list of the words in words that match the given pattern. 
//
// You may return the answer in any order.
//
//  
//
//
// Example 1:
//
//
// Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
// Output: ["mee","aqq"]
// Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}. 
// "ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation,
// since a and b map to the same letter.
//
//  
//
// Note:
//
//
// 	1 <= words.length <= 50
// 	1 <= pattern.length = words[i].length <= 20
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        //直接替换即可
        //col[m]=a col[e]=b e=col[e]
                    vector<string> result;
            map<int,int> store;
            map<int,int> store2;

            for(int i = 0; i < words.size(); i ++)
            {
                int pattern_index = 0;
                int flag = 0;
                store.clear();
                store2.clear();
                for(auto c:words[i])
                {
                    if(store.find(c)==store.end())
                    {
                        if(store2.find(pattern[pattern_index])==store2.end())
                        {
                            store.insert(make_pair(c,pattern[pattern_index]));
                            store2.insert(make_pair(pattern[pattern_index],c));
                        }
                        else
                        {
                            flag = 1;
                            break;
                        }
                    }
                    else
                    {
                        if(store.find(c)->second!=pattern[pattern_index])
                        {
                            flag = 1;
                            break;
                        }
                    }
                    pattern_index ++;
                }
                if(flag==0)
                {
                    result.emplace_back(words[i]);
                }
            }
            return result;
    }
};

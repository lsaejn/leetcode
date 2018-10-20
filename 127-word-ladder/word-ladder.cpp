// Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:
//
//
// 	Only one letter can be changed at a time.
// 	Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
//
//
// Note:
//
//
// 	Return 0 if there is no such transformation sequence.
// 	All words have the same length.
// 	All words contain only lowercase alphabetic characters.
// 	You may assume no duplicates in the word list.
// 	You may assume beginWord and endWord are non-empty and are not the same.
//
//
// Example 1:
//
//
// Input:
// beginWord = "hit",
// endWord = "cog",
// wordList = ["hot","dot","dog","lot","log","cog"]
//
// Output: 5
//
// Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
// return its length 5.
//
//
// Example 2:
//
//
// Input:
// beginWord = "hit"
// endWord = "cog"
// wordList = ["hot","dot","dog","lot","log"]
//
// Output: 0
//
// Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
//
//
//
//
//


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        unordered_set<string> dict(wordList.begin(), wordList.end());//单词的字典
        unordered_map<string, int> m;//单词，和它在答案里的位置
        queue<string> q;//我们需要迭代的单词
        m[beginWord] = 1;//起始单词，位置是1
        q.push(beginWord);
        while (!q.empty())
        {
            string word = q.front(); q.pop();
            for (int i = 0; i < word.size(); ++i)
            {
                string newWord = word;
                for (char ch = 'a'; ch <= 'z'; ++ch) 
                {
                    newWord[i] = ch;//没有任何技巧，就是把所有的可能的结果放到队列里
                    if (dict.count(newWord) && newWord == endWord) return m[word] + 1;
                    if (dict.count(newWord) && !m.count(newWord)) {
                        q.push(newWord);
                        m[newWord] = m[word] + 1;
                    }   
                }
            }
        }
        return 0;
    }
};

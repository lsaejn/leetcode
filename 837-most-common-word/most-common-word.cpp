// Given a paragraph and a list of banned words, return the most frequent word that is not in the list of banned words.  It is guaranteed there is at least one word that isn't banned, and that the answer is unique.
//
// Words in the list of banned words are given in lowercase, and free of punctuation.  Words in the paragraph are not case sensitive.  The answer is in lowercase.
//
//  
//
// Example:
//
//
// Input: 
// paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
// banned = ["hit"]
// Output: "ball"
// Explanation: 
// "hit" occurs 3 times, but it is a banned word.
// "ball" occurs twice (and no other word does), so it is the most frequent non-banned word in the paragraph. 
// Note that words in the paragraph are not case sensitive,
// that punctuation is ignored (even if adjacent to words, such as "ball,"), 
// and that "hit" isn't the answer even though it occurs more because it is banned.
//
//
//  
//
// Note: 
//
//
// 	1 <= paragraph.length <= 1000.
// 	1 <= banned.length <= 100.
// 	1 <= banned[i].length <= 10.
// 	The answer is unique, and written in lowercase (even if its occurrences in paragraph may have uppercase symbols, and even if it is a proper noun.)
// 	paragraph only consists of letters, spaces, or the punctuation symbols !?',;.
// 	There are no hyphens or hyphenated words.
// 	Words only consist of letters, never apostrophes or other punctuation symbols.
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string,int> col;
        istringstream s(paragraph);
        string word;
        while(s>>word)
        {
            if(word.back()==','||word.back()=='.'||word.back()=='!'||word.back()=='?'||word.back()==';'||word.back()=='\'')
                word.pop_back();
            transform(word.begin(),word.end(),word.begin(),[](char c){ return tolower(c);});
            col[word]++;
        }
        unordered_set<string> ban(banned.begin(),banned.end());
        map<int,set<string>,greater<int>> seq;
        for(auto& elem:col)
        {
            seq[elem.second].insert(elem.first);
        }
        for(auto &elem:seq)
        {
            for(auto &s:elem.second)
            if(ban.find(s)==ban.end())
                return s;
        }
        
        
    }
};
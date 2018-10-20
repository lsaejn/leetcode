//
// In English, we have a concept called root, which can be followed by some other words to form another longer word - let's call this word successor. For example, the root an, followed by other, which can form another word another.
//
//
//
//
// Now, given a dictionary consisting of many roots and a sentence. You need to replace all the successor in the sentence with the root forming it. If a successor has many roots can form it, replace it with the root with the shortest length.
//
//
//
// You need to output the sentence after the replacement.
//
//
//
// Example 1:
//
// Input: dict = ["cat", "bat", "rat"]
// sentence = "the cattle was rattled by the battery"
// Output: "the cat was rat by the bat"
//
//
//
//
// Note:
//
// The input will only have lower-case letters.
//  1 <= dict words number <= 1000 
//  1 <= sentence words number <= 1000  
//  1 <= root length <= 100 
//  1 <= sentence words length <= 1000 
//
//


class Solution {
public:
    //题比较简单，就不深究了。这个题的本意是让实现一个前缀树。
    //根节点空，子节点是a-z,以左孩子右兄弟表示最佳，每个子节点又是一颗树
    string replaceWords(vector<string>& dict, string sentence)
    {
        string res = "", t = "";
        vector<vector<string>> v(26);
        
        sort(dict.begin(), dict.end(), [](string &a, string &b) {return a.size() < b.size();});
        for (string word : dict) 
            v[word[0] - 'a'].push_back(word);
        
        istringstream is(sentence);
        while (is >> t) 
        {
            for (string word : v[t[0] - 'a'])
            {
                if (t.substr(0, word.size()) == word) 
                {
                    t = word;
                    break;
                }
            }
            res += t + " ";
        }
        res.pop_back();
        return res; 
    }
};

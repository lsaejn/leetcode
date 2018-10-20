// Design a data structure that supports the following two operations:
//
//
// void addWord(word)
// bool search(word)
//
//
// search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.
//
// Example:
//
//
// addWord("bad")
// addWord("dad")
// addWord("mad")
// search("pad") -> false
// search("bad") -> true
// search(".ad") -> true
// search("b..") -> true
//
//
// Note:
// You may assume that all words are consist of lowercase letters a-z.
//


class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        col.push_back(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word)
    {
        int i=0;
        for(;i!=col.size();++i)
        {
            if(col[i].size()==word.size())
            {
                bool ok=true;
                for(int j=0;j!=word.size();++j)
                {
                    if(word[j]=='.') 
                        continue;
                    else if(word[j]==col[i][j]) 
                        continue;
                    else 
                    {
                        ok=false;
                        break; 
                    }
                }
                if(ok)
                    return true;
            }
        }
        return false;
        
    }
    vector<string> col;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */

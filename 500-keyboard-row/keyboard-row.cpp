// Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below. 
//
//
//
//
//
//
//
// Example 1:
//
// Input: ["Hello", "Alaska", "Dad", "Peace"]
// Output: ["Alaska", "Dad"]
//
//
//
// Note:
//
// You may use one character in the keyboard more than once.
// You may assume the input string will only contain letters of alphabet.
//
//


class Solution {
public:
    vector<string> findWords(vector<string>& words) 
    {
    //1，使用哈希表加快查找速度，一共3个哈希表
    //遍历words,向std一样，使用find看字母第一个位置是否是当前所以，若不是，查询3个哈希表，找不到返回false

        unordered_set<char> row[]={
            {'q','w','e','r','t','y','u','i','o','p'},
            {'a','s','d','f','g','h','j','k','l'},
            {'z','x','c','v','b','n','m'}
        };
        
        vector<string> res;
        for (string word : words) 
        {
            int index=-1;
            for(int i=0;i<sizeof(row)/sizeof(row[0]);++i)
                if (row[i].count(word[0])||(word[0]<'a'&&row[i].count(word[0]+32)) )
                {
                    index = i;
                    break;
                }
            
            
            int j=0;
            for (;j<word.size();++j) 
            {
                char c=word[j];
                if (c < 'a') c += 32;
                if(row[index].count(c)==0) break;
            }
            if(j==word.size())
                res.push_back(word);
        }
        return res;
    }
        
};

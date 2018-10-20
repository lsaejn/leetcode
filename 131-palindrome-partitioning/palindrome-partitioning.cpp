// Given a string s, partition s such that every substring of the partition is a palindrome.
//
// Return all possible palindrome partitioning of s.
//
// Example:
//
//
// Input: "aab"
// Output:
// [
//   ["aa","b"],
//   ["a","a","b"]
// ]
//
//


class Solution {
public:
    //DFS
    //aabbabababccba
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> result;
        vector<string> before;
        helper(s,result,before);
        return result;
        
    }
    
    void helper(string s,vector<vector<string>>& re,vector<string>& before)
    {
        if(s.empty()) 
        {
            re.push_back(before);
        }
        for(int i=1;i<=s.size();++i)
        {
            string temp=s.substr(0,i);
            if(valid(temp))
            {
                before.push_back(temp);
                helper(s.substr(i),re,before); 
                before.pop_back();
            }
        } 
    }
    
    inline bool valid(string& s)
    {
        int i=0;
        int j=s.size()-1;
        while(i<j)
        {
            if(s[i++]!=s[j--])
                return false;
        }
        return true;
    }
    
};

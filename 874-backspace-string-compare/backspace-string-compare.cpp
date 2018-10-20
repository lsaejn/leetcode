// Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.
//
//  
//
//
// Example 1:
//
//
// Input: S = "ab#c", T = "ad#c"
// Output: true
// Explanation: Both S and T become "ac".
//
//
//
// Example 2:
//
//
// Input: S = "ab##", T = "c#d#"
// Output: true
// Explanation: Both S and T become "".
//
//
//
// Example 3:
//
//
// Input: S = "a##c", T = "#a#c"
// Output: true
// Explanation: Both S and T become "c".
//
//
//
// Example 4:
//
//
// Input: S = "a#c", T = "b"
// Output: false
// Explanation: S becomes "c" while T becomes "b".
//
//
//  
//
// Note:
//
//
// 	1 <= S.length <= 200
// 	1 <= T.length <= 200
// 	S and T only contain lowercase letters and '#' characters.
//
//
//
//
//


class Solution {
public:
    bool backspaceCompare(string S, string T) {
        //vector<char> vec1(S.size());
        //vector<char> vec2(T.size());
                vector<char> vec1;
        vector<char> vec2;
        helper(vec1,S);
        helper(vec2,T);
        return vec1==vec2;
    }
    void helper(vector<char>& vec,const string& S)
    {     
        for(char element:S)//处理S中的所有字符，结果存储在v1中
        {
            if(element!='#')  vec.push_back(element);
            else if(!vec.empty())  vec.pop_back();
        }
    }
};

// Given a string S and a character C, return an array of integers representing the shortest distance from the character C in the string.
//
// Example 1:
//
//
// Input: S = "loveleetcode", C = 'e'
// Output: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]
//
//
//  
//
// Note:
//
//
// 	S string length is in [1, 10000].
// 	C is a single character, and guaranteed to be in string S.
// 	All letters in S and C are lowercase.
//
//


class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        //找到所有的e，让他们更新自己周围的值。直到哪个值比先前的小，则break
        vector<int> re(S.size(),INT32_MAX);
        for(int i=0;i!=S.size();++i)
        {
            if(S[i]!=C) 
                continue;
            else
            {
                re[i]=0;
                for(int j=i-1;j>=0;--j)
                {
                    if(S[j]==C) break;
                    if(re[j]<(i-j)) break;
                    else re[j]=i-j;
                }
                for(int k=i+1;k<S.size();++k)
                {
                    if(S[k]==C) break;
                    if(re[k]<(k-i)) break;
                    else re[k]=k-i;
                }
            }            
        }
        return re;
        
    }
};

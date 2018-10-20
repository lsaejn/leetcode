// You are given a license key represented as a string S which consists only alphanumeric character and dashes. The string is separated into N+1 groups by N dashes.
//
// Given a number K, we would want to reformat the strings such that each group contains exactly K characters, except for the first group which could be shorter than K, but still must contain at least one character. Furthermore, there must be a dash inserted between two groups and all lowercase letters should be converted to uppercase.
//
// Given a non-empty string S and a number K, format the string according to the rules described above.
//
// Example 1:
//
// Input: S = "5F3Z-2e-9-w", K = 4
//
// Output: "5F3Z-2E9W"
//
// Explanation: The string S has been split into two parts, each part has 4 characters.
// Note that the two extra dashes are not needed and can be removed.
//
//
//
//
// Example 2:
//
// Input: S = "2-5g-3-J", K = 2
//
// Output: "2-5G-3J"
//
// Explanation: The string S has been split into three parts, each part has 2 characters except the first part as it could be shorter as mentioned above.
//
//
//
// Note:
//
// The length of string S will not exceed 12,000, and K is a positive integer.
// String S consists only of alphanumerical characters (a-z and/or A-Z and/or 0-9) and dashes(-).
// String S is non-empty.
//
//


class Solution {
public:
    //----2,-2-,-21-,-2,---123--4,---12---567
    //这里题目有个没说清楚的地方，比如21-1234-123 会被排成2 1123 4123 因为后面组成一个有效位，所以我们应该从后面往前排
    string licenseKeyFormatting(string S, int K)
    {
        string res = "";
        for (int i = (int)S.size() - 1; i >= 0; --i) 
        {
            if (S[i] != '-') 
            {
                ((res.size() %(K+1) - K) ? res : res += '-') += toupper(S[i]);
            }
        }
        return string(res.rbegin(), res.rend());

    /*
        string result;
        //先把第一个数字串找到，可能是单，也可能是双
        auto pos=S.find_first_not_of("-");
        if(pos==string::npos) return "";
        auto end=S.find_first_of("-",pos);//这里可能有问题
        
        if(end==string::npos) 
        {
            return S.substr(pos,end);  
        }
        size_t startPos=0;
            //pos是最后一个元素
        if(end-pos<K)
        {    
            result+=S.substr(pos,end-pos);
            startPos=end;            
        }
        else
        {
            result+=S.substr(pos,K);
           startPos=pos+K; 
        }
            
        
        int count=0;
        for(;startPos!=S.size();++startPos)
        {
            if(S[startPos]=='-')
                continue;
            else
            {
                if(count==0) result+='-';
                result+=toupper(S[startPos]);
                count++;
                if(count==K)
                {
                    count=0;
                }
            }                        
        }
        return result;
        */
        
    }
};

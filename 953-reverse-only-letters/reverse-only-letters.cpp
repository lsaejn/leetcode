// Given a string S, return the "reversed" string where all characters that are not a letter stay in the same place, and all letters reverse their positions.
//
//  
//
//
//
//
//
//
//
//
//
//
//
// Example 1:
//
//
// Input: "ab-cd"
// Output: "dc-ba"
//
//
//
// Example 2:
//
//
// Input: "a-bC-dEf-ghIj"
// Output: "j-Ih-gfE-dCba"
//
//
//
// Example 3:
//
//
// Input: "Test1ng-Leet=code-Q!"
// Output: "Qedo1ct-eeLg=ntse-T!"
//
//
//  
//
//
// Note:
//
//
// 	S.length <= 100
// 	33 <= S[i].ASCIIcode <= 122 
// 	S doesn't contain \ or "
//
//
//
//
//
//


class Solution {
public:
    string reverseOnlyLetters(string S)
    {
        if(S.empty()) return S;
        size_t left=-1;
        size_t right=S.size();
        while(1)
        {
            while(!isalpha(S[++left]))  if(left == S.size() - 1) break;
            while(!isalpha(S[--right])) if(right==0) break;
            if(left>=right) return S;
            else    swap(S[left],S[right]);
        }
        return S;        
    }
};

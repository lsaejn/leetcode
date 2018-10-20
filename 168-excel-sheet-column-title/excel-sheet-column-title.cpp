// Given a positive integer, return its corresponding column title as appear in an Excel sheet.
//
// For example:
//
//
//     1 -> A
//     2 -> B
//     3 -> C
//     ...
//     26 -> Z
//     27 -> AA
//     28 -> AB 
//     ...
//
//
// Example 1:
//
//
// Input: 1
// Output: "A"
//
//
// Example 2:
//
//
// Input: 28
// Output: "AB"
//
//
// Example 3:
//
//
// Input: 701
// Output: "ZY"
//
//


class Solution {
public:
    const string ALPHAB=" ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string convertToTitle(int n) {
        
        string result;
        while (n) //27-52 AA-AZ 53 BA //如果在这里做除法，没办法处理26的倍数，采用模后除的办法12345%10/10%10/10
        {
            --n;
            result +=(n%26 + 'A');
            n /= 26;
        }
        reverse(result.begin(),result.end());
        return result;
    }
};

//
// There is a strange printer with the following two special requirements:
//
//
// The printer can only print a sequence of the same character each time.
// At each turn, the printer can print new characters starting from and ending at any places, and will cover the original existing characters.
//
//
//
//
//
// Given a string consists of lower English letters only, your job is to count the minimum number of turns the printer needed in order to print it.
//
//
// Example 1:
//
// Input: "aaabbb"
// Output: 2
// Explanation: Print "aaa" first and then print "bbb".
//
//
//
// Example 2:
//
// Input: "aba"
// Output: 2
// Explanation: Print "aaa" first and then print "b" from the second place of the string, which will cover the existing character 'a'.
//
//
//
// Hint: Length of the given string will not exceed 100.


    //aabbbaa,2
    //aabbb,2
    //aabbcc,3  aabbccaa,3,aabbccdd,4,aabbccddaa,4
    //找到相同的地方打印，可以省1次
    //aabbccddbbaa
    //第一步，去重abcdba似乎变成了回文串长度/2+非回文
class Solution
{
private:
    int f[100][100];
    
private:
    int dfs(const std::string& s, int l, int r)
    {
        if (l > r) return 0;
        if (f[l][r]) return f[l][r];
        f[l][r] = dfs(s, l, r - 1) + 1;
        for (int i = l; i < r; ++i)
        {
            if (s[i] == s[r])
            {
                f[l][r] = std::min(f[l][r], dfs(s, l, i) + dfs(s, i + 1, r - 1));
            }
        }
        return f[l][r];
    }
    
public:
    int strangePrinter(std::string s)
    {
        s.erase(unique(s.begin(),s.end()),s.end());
        memset(f, 0, sizeof(f));
        int len = (int)s.size();
        return dfs(s, 0, len - 1);
    }
};

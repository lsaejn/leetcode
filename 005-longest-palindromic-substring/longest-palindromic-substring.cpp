// Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
//
// Example 1:
//
//
// Input: "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.
//
//
// Example 2:
//
//
// Input: "cbbd"
// Output: "bb"
//
//


class Solution {
public:
    string longestPalindrome(string s) {
			s = Manacher(s);
			string result;
			for (int i = 1; i != s.size(); ++i)
			{
				for (int j = 1; i - j >= 0 && i + j<s.size(); ++j)
				{
					if (s[i + j] == s[i - j])
					{						
						if (2*j+1>result.size()) 
                            result = s.substr(i - j, 2*j+1);
					}
					else break;
				}

			}
			result.erase(remove(result.begin(), result.end(), '#'), result.end());
			return result;       
    }
    
    string Manacher(string& s) {
    // Insert '#'
    string t = "#";
    for (int i = 0; i < s.size(); ++i) 
    {
        t += s[i];
        t += "#";
    }
        return t;
    }
};

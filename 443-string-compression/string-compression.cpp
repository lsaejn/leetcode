// Given an array of characters, compress it in-place.
//
// The length after compression must always be smaller than or equal to the original array.
//
// Every element of the array should be a character (not int) of length 1.
//
// After you are done modifying the input array in-place, return the new length of the array.
//
//
//
// Follow up:
// Could you solve it using only O(1) extra space?
//
//
//
//
// Example 1:
//
// Input:
// ["a","a","b","b","c","c","c"]
//
// Output:
// Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
//
// Explanation:
// "aa" is replaced by "a2". "bb" is replaced by "b2". "ccc" is replaced by "c3".
//
//
//
// Example 2:
//
// Input:
// ["a"]
//
// Output:
// Return 1, and the first 1 characters of the input array should be: ["a"]
//
// Explanation:
// Nothing is replaced.
//
//
//
// Example 3:
//
// Input:
// ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
//
// Output:
// Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].
//
// Explanation:
// Since the character "a" does not repeat, it is not compressed. "bbbbbbbbbbbb" is replaced by "b12".
// Notice each digit has it's own entry in the array.
//
//
//
// Note:
//
// All characters have an ASCII value in [35, 126].
// 1 <= len(chars) <= 1000.
//
//


class Solution {
public:
    int compress(vector<char>& chars) {
        /*
        sort(chars.begin(),chars.end());
        vector<int> col(126);
        for(int i=0;i!=chars.size();++i)
        {
            col[chars[i]]++;
        }
        char before='-1';
        string result;
        for(int i=0;i!=chars.size();++i)
        {
            if(chars[i]==before)
            {}
            else
            {
                result.push_back(chars[i]);
                if(col[chars[i]]!=1)
                result+=(to_string(col[chars[i]]));
                before=chars[i];
            }

        }
        chars.clear();
        for(auto elem:result)
            chars.push_back(elem);
        return chars.size();
        */
              int n = chars.size();

        vector<char> tmp = chars;
        chars.clear();
        
        for (int i = 0; i < n; ++i) {
            int x = 1;
            while(i+1 < n && tmp[i] == tmp[i+1]) {
                ++i;
                x++;
            }
            if (x == 1) {
                chars.push_back(tmp[i]);
            } else if (x >= 2) {
                chars.push_back(tmp[i]);
                vector<char> s;
                while(x > 0) {
                    s.push_back(char(x%10 +'0'));
                    x /= 10;
                }
                for (int j = s.size()-1; j >= 0; --j) chars.push_back(s[j]);
            }
        }
        return chars.size();
    }
};

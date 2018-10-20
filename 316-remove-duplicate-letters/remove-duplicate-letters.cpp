// Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.
//
// Example 1:
//
//
// Input: "bcabc"
// Output: "abc"
//
//
// Example 2:
//
//
// Input: "cbacdcbc"
// Output: "acdb"
//
//


class Solution {
public:
    //先统计依次
    string removeDuplicateLetters(string s) {
        int m[256] = {0}, visited[256] = {0};
        string res = "0";
        for (auto a : s) 
            ++m[a];
        for (auto a : s) 
        {
            --m[a];
            if (visited[a]) continue;
            while (a < res.back() && m[res.back()])
            {
                visited[res.back()] = 0;
                res.pop_back();
            }
            res += a;
            visited[a] = 1;
        }
        return res.substr(1); 
    }
};

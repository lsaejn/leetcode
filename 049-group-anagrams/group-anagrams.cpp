// Given an array of strings, group anagrams together.
//
// Example:
//
//
// Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
// Output:
// [
//   ["ate","eat","tea"],
//   ["nat","tan"],
//   ["bat"]
// ]
//
// Note:
//
//
// 	All inputs will be in lowercase.
// 	The order of your output does not matter.
//
//


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;
        for (string str : strs) 
        {
            vector<int> cnt(26, 0);
            string t = "";
            for (char c : str) 
                ++cnt[c - 'a'];
            for (int d : cnt) 
                t += to_string(d);
            m[t].push_back(str);
        }
        for (auto a : m) 
        {
            res.push_back(a.second);
        }
        return res;
    }
};

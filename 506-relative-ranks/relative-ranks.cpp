//
// Given scores of N athletes, find their relative ranks and the people with the top three highest scores, who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".
//
// Example 1:
//
// Input: [5, 4, 3, 2, 1]
// Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
// Explanation: The first three athletes got the top three highest scores, so they got "Gold Medal", "Silver Medal" and "Bronze Medal". For the left two athletes, you just need to output their relative ranks according to their scores.
//
//
//
// Note:
//
// N is a positive integer and won't exceed 10,000.
// All the scores of athletes are guaranteed to be unique.
//
//
//


class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        //对于查找，哈希表是最快的
        int cnt = 1;
        vector<string> res(nums.size(), "");
        map<int, int,greater<int>> m;//原解用到了反序输出，其实大可不必
        for (int i = 0; i < nums.size(); ++i)
            m[nums[i]] = i;
        for (auto it = m.begin(); it != m.end(); ++it) 
        {
            if (cnt == 1) res[it->second] = "Gold Medal";
            else if (cnt == 2) res[it->second] = "Silver Medal";
            else if (cnt == 3) res[it->second] = "Bronze Medal";
            else res[it->second] = to_string(cnt);
            ++cnt;
        }
        return res;
    }
};

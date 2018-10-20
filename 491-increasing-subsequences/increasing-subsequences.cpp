//
// Given an integer array, your task is to find all the different possible increasing subsequences of the given array, and the length of an increasing subsequence should be at least 2 .
//
//
// Example:
//
// Input: [4, 6, 7, 7]
// Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]
//
//
//
// Note:
//
// The length of the given array will not exceed 15.
// The range of integer in the given array is [-100,100].
// The given array may contain duplicates, and two equal integers should also be considered as a special case of increasing sequence.
//
//


class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> res;
        vector<vector<int>> cur(1);
        for (int i = 0; i < nums.size(); ++i) {
            int n = cur.size();
            for (int j = 0; j < n; ++j) {
                if (!cur[j].empty() && cur[j].back() > nums[i]) continue;
                cur.push_back(cur[j]);
                cur.back().push_back(nums[i]);
                if (cur.back().size() >= 2) res.insert(cur.back());
            }
        }
        return vector<vector<int>>(res.begin(), res.end());
    }
};

// You have k lists of sorted integers in ascending order. Find the smallest range that includes at least one number from each of the k lists. 
//
// We define the range [a,b] is smaller than range [c,d] if b-a < d-c or a < c if b-a == d-c.
//
// Example 1:
//
// Input:[[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]
// Output: [20,24]
// Explanation: 
// List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
// List 2: [0, 9, 12, 20], 20 is in range [20,24].
// List 3: [5, 18, 22, 30], 22 is in range [20,24].
//
//
//
//
// Note:
//
// The given list may contain duplicates, so ascending order means >= here.
// 1 <= k <= 3500
//  -105 <= value of elements <= 105.
// For Java users, please note that the input type has been changed to List<List<Integer>>. And after you reset the code template, you'll see this point.
//
//
//


class Solution {
public:
    //放到一起，记录3个数组出现的个数。滑动窗口
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> res;
        vector<pair<int, int>> v;
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            for (int num : nums[i]) {
                v.push_back({num, i});
            }
        }
        sort(v.begin(), v.end());
        int left = 0, n = v.size(), k = nums.size(), cnt = 0, diff = INT_MAX;
        for (int right = 0; right < n; ++right) {
            if (m[v[right].second] == 0) ++cnt;
            ++m[v[right].second];
            while (cnt == k && left <= right) {
                if (diff > v[right].first - v[left].first) {
                    diff = v[right].first - v[left].first;
                    res = {v[left].first, v[right].first};
                } 
                if (--m[v[left].second] == 0) --cnt;
                ++left;
            }
        }
        return res;
    }
};

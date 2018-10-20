// You have a number of envelopes with widths and heights given as a pair of integers (w, h). One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.
//
//
// What is the maximum number of envelopes can you Russian doll? (put one inside other)
//
//
// Example:
// Given envelopes = [[5,4],[6,4],[6,7],[2,3]], the maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
//


class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        vector<int> dp;
        //[2,3],[5,4],[6,7],[6,6],[6,4],[7,8]
        sort(envelopes.begin(), envelopes.end(), [](const pair<int, int> &a, const pair<int, int> &b){
            if (a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        });

        for (int i = 0; i < envelopes.size(); ++i) 
        {
            auto it = lower_bound(dp.begin(), dp.end(), envelopes[i].second);
            if (it == dp.end()) 
                dp.push_back(envelopes[i].second);
            else 
                *it = envelopes[i].second;
        }
        return dp.size();
    }
};

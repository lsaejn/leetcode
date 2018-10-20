// Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:
//
// Si % Sj = 0 or Sj % Si = 0.
//
// If there are multiple solutions, return any subset is fine.
//
// Example 1:
//
//
//
// Input: [1,2,3]
// Output: [1,2] (of course, [1,3] will also be ok)
//
//
//
// Example 2:
//
//
// Input: [1,2,4,8]
// Output: [1,2,4,8]
//
//
//
//


class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.size()<2) return nums;                      //if the size is less than 2, return nums as the answer

        sort(nums.begin(), nums.end());
        
        int choose = 0;
        int nums_size = nums.size();
        vector<int> ans;
        vector<int> dp(nums.size(), 1);                     //dp[i]: the largest length of the subset range from 0 to i
        vector<int> fa(nums.size(), 0);                     //fa[i]: previous/father index or itself

        for(int i=1; i<nums_size; ++i){
            fa[i] = i;
            for(int j=0; j<i&&nums[j]<=nums[i]/2; ++j){     // if y in (x/2, x), x%y!=0
                if(nums[i]%nums[j]==0 && dp[j]>=dp[i]){
                    dp[i] = dp[j]+1;
                    fa[i] = j;                              //record its previous/father index
                    if(dp[choose] < dp[i]) choose = i;      //variable 'choose' is the last index of the possible subset
                }
            }
        }

        while(fa[choose]!=choose){
            ans.push_back(nums[choose]);
            choose = fa[choose];
        }
        ans.push_back(nums[choose]);

        // sort(ans.begin(), ans.end());
        return ans;
    }
};

// Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
//
// The same repeated number may be chosen from candidates unlimited number of times.
//
// Note:
//
//
// 	All numbers (including target) will be positive integers.
// 	The solution set must not contain duplicate combinations.
//
//
// Example 1:
//
//
// Input: candidates = [2,3,6,7], target = 7,
// A solution set is:
// [
//   [7],
//   [2,2,3]
// ]
//
//
// Example 2:
//
//
// Input: candidates = [2,3,5], target = 8,
// A solution set is:
// [
//   [2,2,2,2],
//   [2,3,3],
//   [3,5]
// ]
//
//


class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>> result;
        vector<int> before;
        combinationSum(result,candidates,target,before);
        for(auto &elem:result)
        {
            sort(elem.begin(),elem.end());
        }
        sort(result.begin(),result.end());
        result.erase(unique(result.begin(),result.end()),result.end());
        return result;
    }
    void combinationSum(vector<vector<int>>& result,vector<int>& nums, int target,vector<int>& before) 
    {
        for(int i=0;i!=nums.size();++i)
        {
            if(nums[i]<target) 
            {
                before.push_back(nums[i]);
                combinationSum(result,nums,target-nums[i],before);
                before.pop_back();
            }
            if(nums[i]==target) 
            {
                before.push_back(nums[i]);
                result.push_back(before);
                before.pop_back();
                //break;
            }
            else 
                continue;
        }        
    }
};

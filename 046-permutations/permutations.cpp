// Given a collection of distinct integers, return all possible permutations.
//
// Example:
//
//
// Input: [1,2,3]
// Output:
// [
//   [1,2,3],
//   [1,3,2],
//   [2,1,3],
//   [2,3,1],
//   [3,1,2],
//   [3,2,1]
// ]
//
//


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size()==0) return {};
        vector<vector<int>> re;
        vector<int> before;
        permute(nums,0,re,before);
        return re;
    }
    void permute(vector<int>& nums,int pos,vector<vector<int>>& result,vector<int>& before)
    {
        if(pos==nums.size()) 
        {
            result.push_back(before);
            return;
        }  
        for(int i=pos;i!=nums.size();++i)
        {
            swap(nums[pos],nums[i]);
            //vector<int> vec(nums.begin()+1,nums.end());
            before.push_back(nums[pos]);
            permute(nums,pos+1,result,before);
            before.pop_back();
            swap(nums[pos],nums[i]);
        }
        
    }
};

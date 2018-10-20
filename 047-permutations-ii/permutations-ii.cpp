// Given a collection of numbers that might contain duplicates, return all possible unique permutations.
//
// Example:
//
//
// Input: [1,1,2]
// Output:
// [
//   [1,1,2],
//   [1,2,1],
//   [2,1,1]
// ]
//
//


class Solution {
public:
    //有大量重复的情况下，尝试避免无效遍历
    //1112
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        //为此，我们sort一次
        if(nums.size()==0) return {};
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        vector<int> before;
        permuteUnique(nums,0,result,before);
        sort(result.begin(),result.end());//这样不能避免重复的情况，
        //比如00019,我们的交换会让顺序变成90010,它不是有序的。依次产生90010 90001 90100 90010...显然很早就重复了
        //为此，我们需要在permuteUnique里，每次都sort一次再遍历。。
        result.erase(unique(result.begin(),result.end()),result.end());
        return result;
        //
        
    }
    
    int count=1; 
    void permuteUnique(vector<int>& nums,int begin,vector<vector<int>>& result,vector<int>& before) 
    {
        count++;
        if(nums.size()==before.size()&&begin==nums.size())
        {
            result.push_back(before);
            return;
        }
        for(int i=begin;i<nums.size();++i)//112
        {
            if(i>begin&&nums[i]==nums[i-1]) 
                continue;
            swap(nums[begin],nums[i]);
            before.push_back(nums[begin]);
            permuteUnique(nums,begin+1,result,before);
            before.pop_back();
            swap(nums[begin],nums[i]);
        }
    }
};

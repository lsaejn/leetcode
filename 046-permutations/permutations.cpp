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
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


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

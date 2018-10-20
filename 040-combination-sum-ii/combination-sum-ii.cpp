// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
//
// Each number in candidates may only be used once in the combination.
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
// Input: candidates = [10,1,2,7,6,1,5], target = 8,
// A solution set is:
// [
//   [1, 7],
//   [1, 2, 5],
//   [2, 6],
//   [1, 1, 6]
// ]
//
//
// Example 2:
//
//
// Input: candidates = [2,5,2,1,2], target = 5,
// A solution set is:
// [
//   [1,2,2],
//   [5]
// ]
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


static const auto _ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<vector<int>> getCandidates(vector<int>& candidates, int begin, int target)
    {
        int subtarget;
        vector<vector<int>> res;
        vector<vector<int>> result;
        
        for ( int i = begin; i < candidates.size(); i++)
        {   
            if ( i > begin && candidates[i] == candidates[i-1])
                continue;
            subtarget = target - candidates[i];
            if ( subtarget == 0)
            {
                result.push_back({target});
                return result;
            }
            else if ( subtarget < 0)
            {
                return result;
            }
           
            res = getCandidates(candidates, i+1, subtarget);

            for (auto iter = res.begin(); iter != res.end(); ++iter)
            {
                if ( iter->size() != 0)
                {                   
                    iter->insert(iter->begin(), candidates[i]);
                    result.push_back(*iter);
                }
            }            
        }       
        return result;
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;       
        result = getCandidates(candidates, 0, target);               
        return result;
    }
};

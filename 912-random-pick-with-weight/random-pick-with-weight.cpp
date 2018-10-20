// Given an array w of positive integers, where w[i] describes the weight of index i, write a function pickIndex which randomly picks an index in proportion to its weight.
//
// Note:
//
//
// 	1 <= w.length <= 10000
// 	1 <= w[i] <= 10^5
// 	pickIndex will be called at most 10000 times.
//
//
// Example 1:
//
//
// Input: 
// ["Solution","pickIndex"]
// [[[1]],[]]
// Output: [null,0]
//
//
//
// Example 2:
//
//
// Input: 
// ["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
// [[[1,3]],[],[],[],[],[]]
// Output: [null,0,1,1,1,0]
//
//
// Explanation of Input Syntax:
//
// The input is two lists: the subroutines called and their arguments. Solution's constructor has one argument, the array w. pickIndex has no arguments. Arguments are always wrapped with a list, even if there aren't any.
//



    //这个题目不太好理解，是要求按照权重挑选索引。比如[1,99]中，有1%的概率挑选到索引0，有99%的概率挑选到索引1.
    /*
    比如，输入是[1,2,3,4]，那么概率分布是[1/10, 2/10, 3/10, 4/10]，累积概率分布是[1/10, 3/10, 6/10, 10/10].总和是10。如果我们产生一个随机数，在0~9之中，然后判断这个数字在哪个区间中就能得到对应的索引。
    */
class Solution {
public:
    vector<int> ps;
    Solution(vector<int> w) {
        partial_sum(w.begin(),w.end(),back_inserter(ps));
        srand(time(NULL));
    }
    
    int pickIndex() {
        int r = rand() %  ps.back();
        auto ub = upper_bound(ps.begin(),ps.end(),r);
        return distance(ps.begin(),ub);
    }
};    


/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */

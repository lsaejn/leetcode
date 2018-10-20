// Given a blacklist B containing unique integers from [0, N), write a function to return a uniform random integer from [0, N) which is NOT in B.
//
// Optimize it such that it minimizes the call to system’s Math.random().
//
// Note:
//
//
// 	1 <= N <= 1000000000
// 	0 <= B.length < min(100000, N)
// 	[0, N) does NOT include N. See interval notation.
//
//
// Example 1:
//
//
// Input: 
// ["Solution","pick","pick","pick"]
// [[1,[]],[],[],[]]
// Output: [null,0,0,0]
//
//
// Example 2:
//
//
// Input: 
// ["Solution","pick","pick","pick"]
// [[2,[]],[],[],[]]
// Output: [null,1,1,1]
//
//
// Example 3:
//
//
// Input: 
// ["Solution","pick","pick","pick"]
// [[3,[1]],[],[],[]]
// Output: [null,0,0,2]
//
//
// Example 4:
//
//
// Input: 
// ["Solution","pick","pick","pick"]
// [[4,[2]],[],[],[]]
// Output: [null,1,3,1]
//
//
// Explanation of Input Syntax:
//
// The input is two lists: the subroutines called and their arguments. Solution's constructor has two arguments, N and the blacklist B. pick has no arguments. Arguments are always wrapped with a list, even if there aren't any.
//


class Solution {
public:
    //rehash当然很快，但是我更喜欢这个解法，很巧妙，而且你很难忘记
    vector<int> v;
    std::mt19937 gen;
    std::uniform_int_distribution<> dis;
    Solution(int N, vector<int> blacklist) {
        v = blacklist;
        sort(v.begin(), v.end());
        v.push_back(N);//我们要找upper,所以一定要加N
        for (int i = 0; i < v.size(); i++) v[i] -= i;
        
        std::random_device rd;  //Will be used to obtain a seed for the random number engine
        gen = std::mt19937(rd()); //Standard mersenne_twister_engine seeded with rd()
        dis = std::uniform_int_distribution<>(0, N - v.size());
    }
    
    int pick() {
        int rnd = dis(gen);
        auto it = upper_bound(v.begin(), v.end(), rnd) - 1;
        int idx = it - v.begin();
        return idx + rnd + 1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(N, blacklist);
 * int param_1 = obj.pick();
 */

// Given a non-empty integer array of size n, find the minimum number of moves required to make all array elements equal, where a move is incrementing n - 1 elements by 1.
//
// Example:
//
// Input:
// [1,2,3]
//
// Output:
// 3
//
// Explanation:
// Only three moves are needed (remember each move increments two elements):
//
// [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
//
//


class Solution {
public:
    int minMoves(vector<int>& nums) {
        //第一感觉就是用递归，每次选择一个不增加的数。但这样可能一直得不到结果
        //1234->4564 6766
        //过程是 max    min
        /*
          1->4 3+(4-1)  4
          4->6 2+4-1+2  6
          6->7 7        7
        */
        
        //我们得到规律，每次找到最大值，将其他元素+1，直到相等
        //1,60,100. 159 =99+59
        int mn = INT_MAX, res = 0;
        for (int num : nums)
            mn = min(mn, num);
        for (int num : nums) 
            res += num - mn;
        return res;
    }
};

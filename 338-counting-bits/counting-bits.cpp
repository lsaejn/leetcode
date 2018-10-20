// Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.
//
//
// Example:
// For num = 5 you should return [0,1,1,2,1,2].
//
//
// Follow up:
//
// It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
// Space complexity should be O(n).
// Can you do it like a boss? Do it without using any builtin function like __builtin_popcount  in c++ or in any other language.
//
//
//
// Credits:Special thanks to @ syedee  for adding this problem and creating all test cases.


class Solution {
public:
    //如果每个数都计算，时间复杂度将会是O(n**2),
    //规律是，从1开始，遇到偶数时，其1的个数和该偶数除以2得到的数字的1的个数相同，遇到奇数时，其1的个数等于该奇数除以2得到的数字的1的个数再加1，
    vector<int> countBits(int num)
    {
        vector<int> res{0};
        for (int i = 1; i <= num; ++i) {
            if (i % 2 == 0) res.push_back(res[i / 2]);
            else res.push_back(res[i / 2] + 1);
        }
        return res;    
    }
};

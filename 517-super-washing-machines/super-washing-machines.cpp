// You have n super washing machines on a line. Initially, each washing machine has some dresses or is empty. 
//
//
// For each move, you could choose any m (1 ≤ m ≤ n) washing machines, and pass one dress of each washing machine to one of its adjacent washing machines  at the same time .  
//
// Given an integer array representing the number of dresses in each washing machine from left to right on the line, you should find the minimum number of moves to make all the washing machines have the same number of dresses. If it is not possible to do it, return -1.
//
// Example1
//
// Input: [1,0,5]
//
// Output: 3
//
// Explanation: 
// 1st move:    1     0 <-- 5    =>    1     1     4
// 2nd move:    1 <-- 1 <-- 4    =>    2     1     3    
// 3rd move:    2     1 <-- 3    =>    2     2     2   
//
//
// Example2
//
// Input: [0,3,0]
//
// Output: 2
//
// Explanation: 
// 1st move:    0 <-- 3     0    =>    1     2     0    
// 2nd move:    1     2 --> 0    =>    1     1     1     
//
//
// Example3
//
// Input: [0,2,0]
//
// Output: -1
//
// Explanation: 
// It's impossible to make all the three washing machines have the same number of dresses. 
//
//
//
//
// Note:
//
// The range of n is [1, 10000].
// The range of dresses number in a super washing machine is [0, 1e5].
//
//


class Solution {
public:
    //仔细观察，如果一个元素左边缺n达到平均水平，无论如何你都要移动n次，同理右边也是一样
    //再考虑一个需要移动最多次的元素，最大值就在它们之间产生
    //比如1281,8无论如何也要移动5次，那么它的左边需要它移动3次，右边需要2次，
    //如果两边都缺，那么移动次数为求和
    //否则只要移动那个最大值就行了，
int findMinMoves(vector<int>& machines) 
{
    int totalDresses = 0, size = machines.size();
    for (auto i = 0; i < size; ++i) 
        totalDresses += machines[i];
    if (totalDresses % size != 0) 
        return -1;
    
    auto targetDresses = totalDresses / size, totalMoves = 0, ballance = 0;
    for (auto i = 0; i < size; ++i) {
        ballance += machines[i] - targetDresses;
        totalMoves = max(totalMoves, max(machines[i] - targetDresses, abs(ballance)));
    }
    return totalMoves;
}
};

// In the "100 game," two players take turns adding, to a running total, any integer from 1..10. The player who first causes the running total to reach or exceed 100 wins. 
//
// What if we change the game so that players cannot re-use integers? 
//
// For example, two players might take turns drawing from a common pool of numbers of 1..15 without replacement until they reach a total >= 100.
//
// Given an integer maxChoosableInteger and another integer desiredTotal, determine if the first player to move can force a win, assuming both players play optimally. 
//
// You can always assume that maxChoosableInteger will not be larger than 20 and desiredTotal will not be larger than 300.
//
//
// Example
//
// Input:
// maxChoosableInteger = 10
// desiredTotal = 11
//
// Output:
// false
//
// Explanation:
// No matter which integer the first player choose, the first player will lose.
// The first player can choose an integer from 1 up to 10.
// If the first player choose 1, the second player can only choose integers from 2 up to 10.
// The second player will win by choosing 10 and get a total = 11, which is >= desiredTotal.
// Same with other integers chosen by the first player, the second player will always win.
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //maxChoosableInteger will not be larger than 20 and desiredTotal will not be larger than 300.
    //所以我们可以用bitset记录数字的选中状态，比如[5,8]到play1选的时候，1-5的状态是00111，显然这个状态选5必定能获得胜利
    //
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger >= desiredTotal) return true;
        if (maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal) return false;
        unordered_map<int, bool> m;
        return canWin(maxChoosableInteger, desiredTotal, 0, m);
    }
    
    bool canWin(int length, int total, int used, unordered_map<int, bool>& m)
    {
        if (m.count(used)) return m[used];
        for (int i = 0; i < length; ++i)
        {
            int cur = (1 << i);//
            if ((cur & used) == 0)//
            {
                if (total <= i + 1 || !canWin(length, total - (i + 1), cur | used, m))
                {
                    m[used] = true;//这个used很难理解，它代表数字被选择的情况下能不能获胜
                    return true;
                }
            }
        }
        m[used] = false;
        return false;
    }
};

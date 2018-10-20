// There are N dominoes in a line, and we place each domino vertically upright.
//
// In the beginning, we simultaneously push some of the dominoes either to the left or to the right.
//
//
//
// After each second, each domino that is falling to the left pushes the adjacent domino on the left.
//
// Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.
//
// When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.
//
// For the purposes of this question, we will consider that a falling domino expends no additional force to a falling or already fallen domino.
//
// Given a string "S" representing the initial state. S[i] = 'L', if the i-th domino has been pushed to the left; S[i] = 'R', if the i-th domino has been pushed to the right; S[i] = '.', if the i-th domino has not been pushed.
//
// Return a string representing the final state. 
//
// Example 1:
//
//
// Input: ".L.R...LR..L.."
// Output: "LL.RR.LLRRLL.."
//
//
// Example 2:
//
//
// Input: "RR.L"
// Output: "RR.L"
// Explanation: The first domino expends no additional force on the second domino.
//
//
// Note:
//
//
// 	0 <= N <= 10^5
// 	String dominoes contains only 'L', 'R' and '.'
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //通常都是用两个dp记录LR的距离，但是这个用了1个dp，
    //先看从左向右扫描，左边有没有R，有就置本.为R，更新最近的R的距离
    //然后从右向左扫描。比较L和R即可。
    //自己一开始就倒的，值为0，所以不会收影响
    string pushDominoes(string dominoes) {
        const int n = dominoes.size();
        vector<int> vt(n);
        for(int i = 1; i < n; ++i){
            if(dominoes[i-1] == 'R' && dominoes[i] == '.')
            {
                dominoes[i] = 'R';
                vt[i] = vt[i-1] + 1;
            }
        }

        for(int i = n-2, nt; i >= 0; --i){
            if(dominoes[i+1] == 'L')
            {
                nt = vt[i+1] + 1;
                if(dominoes[i] == '.' || vt[i] > nt){
                    dominoes[i] = 'L';
                    vt[i] = nt;
                }
                else if(dominoes[i] == 'R' && vt[i] == nt){ // recover
                    dominoes[i] = '.';
                }
            }
        }
        return dominoes;
    }
};

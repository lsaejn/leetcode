// Given several boxes with different colors represented by different positive numbers. 
// You may experience several rounds to remove boxes until there is no box left. Each time you can choose some continuous boxes with the same color (composed of k boxes, k >= 1), remove them and get k*k points.
// Find the maximum points you can get.
//
//
// Example 1:
// Input: 
//
// [1, 3, 2, 2, 2, 3, 4, 3, 1]
//
// Output:
//
// 23
//
// Explanation: 
//
// [1, 3, 2, 2, 2, 3, 4, 3, 1] 
// ----> [1, 3, 3, 4, 3, 1] (3*3=9 points) 
// ----> [1, 3, 3, 3, 1] (1*1=1 points) 
// ----> [1, 1] (3*3=9 points) 
// ----> [] (2*2=4 points)
//
//
//
// Note:
// The number of boxes n would not exceed 100.
//
//


class Solution {
public:
    //我们不清楚怎么消除可以获得最高分
    //先做个假设，每次移除最多数量的必定可以得到最高分，怼一下测试用例，显然不对
    //比如下例，5个2，可以获得25分，需要移除中间4个元素，我们只需对4个数字递归调用函数
    //但是你怎么知道移除4个元素比移除2更糟糕呢，比如13222334223333331313,又该怎么做呢.用深度遍历是不可能的
    //[1, 3, 2, 2, 2, 3, 4, 3, 1，2,2]->[1334312]->[133312]->[112]-?[2]-?[]//24
    //[1322234312]->[132223312]->[1322212]->[132222]->[13]->[3]->[1]//24
    //那么考虑动态规划。
    /*
三维数组dp[i][j][k]，表示区间[i, j]中能获得的最大积分，当boxes[i]左边有k个数字跟其相等。那么我们的目标就是要求dp[0][n-1][0]。而且我们也能推出dp[i][i][k] = (1+k) * (1+k)这个等式。那么我们来推导重现关系，对于dp[i][j][k]，如果我们移除boxes[i]，那么我们得到(1+k)*(1+k) + dp[i+1][j][0]。
有个关键信息在这里:当某个位置m，有boxes[i] == boxes[m]时，我们也应该考虑先移除[i+1,m-1]这部分，我们得到积分dp[i+1][m-1][0]，然后再处理剩下的部分，得到积分dp[m][j][k+1]，这里k加1点原因是，移除了中间的部分后，原本和boxes[m]不相邻的boxes[i]现在相邻了，又因为二者值相同，所以k应该加1，因为k的定义就是左边相等的数字的个数。
    */
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        vector<vector<int>> nv(n,vector<int>(n));
        vector<vector<vector<int>>> dp(n,nv);
        return helper(boxes, 0, n - 1, 0, dp);
    }
    //i~j之前，且i之前有k个连续数字，能获得的最大分数
    int helper(vector<int>& boxes, int i, int j, int k, vector<vector<vector<int>>>& dp) 
    {
        if (j < i) return 0;
        if (dp[i][j][k] > 0) return dp[i][j][k];
        int res = (1 + k) * (1 + k) + helper(boxes, i + 1, j, 0, dp);
        for (int m = i + 1; m <= j; ++m) {
            if (boxes[m] == boxes[i]) {
                res = max(res, helper(boxes, i + 1, m - 1, 0, dp) + helper(boxes, m, j, k + 1, dp));//!!
            }
        }
        return dp[i][j][k] = res;
    }
};

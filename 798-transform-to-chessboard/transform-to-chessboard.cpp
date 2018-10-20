// An N x N board contains only 0s and 1s. In each move, you can swap any 2 rows with each other, or any 2 columns with each other.
//
// What is the minimum number of moves to transform the board into a "chessboard" - a board where no 0s and no 1s are 4-directionally adjacent? If the task is impossible, return -1.
//
//
// Examples:
// Input: board = [[0,1,1,0],[0,1,1,0],[1,0,0,1],[1,0,0,1]]
// Output: 2
// Explanation:
// One potential sequence of moves is shown below, from left to right:
//
// 0110     1010     1010
// 0110 --> 1010 --> 0101
// 1001     0101     1010
// 1001     0101     0101
//
// The first move swaps the first and second column.
// The second move swaps the second and third row.
//
//
// Input: board = [[0, 1], [1, 0]]
// Output: 0
// Explanation:
// Also note that the board with 0 in the top left corner,
// 01
// 10
//
// is also a valid chessboard.
//
// Input: board = [[1, 0], [1, 0]]
// Output: -1
// Explanation:
// No matter what sequence of moves you make, you cannot end with a valid chessboard.
//
//
// Note:
//
//
// 	board will have the same number of rows and columns, a number in the range [2, 30].
// 	board[i][j] will be only 0s or 1s.
//
//


class Solution {
public:
    /*
    通过观察，我们发现一个合法的原始棋盘必须具备如下两个条件：
1）只能有且仅有两种行类型，例如如果一种行类型为01010011，那么另外一种行类型只能为01010011或者10101100；该限制条件同样适合于列类型。此外，任何棋盘内部的四边形，要么四个角都是1，要么四个角都是0，要么两个0和两个1。

2）每一行和每一列中，0和1的数量都是相等的，假设棋盘是N * N大小的，那么：a）如果N = 2 * K，那么每一行每一列有且仅有K个0和K个1；b）如果N = 2 * K + 1，那么每一行每一列要么有K个1和K+1个0，要么有K+1个1和K个0。

由于每次的行交换和列交换都不破坏上述性质，所以以上两个条件就成了判断是否可以形成合法棋盘的充要条件。一旦我们判断出来某个棋盘是合法的，我们就开始计算最小的交换次数。基于上述性质，我们对第一行进行整理（通过交换列来实现），以N = 5为例来说明：

1）如果N是偶数，我们计算实现01010和10101需要的最小移动步数，并且取最小者；

2）如果N是奇数，我们就只有一种取法，所以就取移动步数为偶数的最小次数。

总之，我感觉这道题目还是挺难的，而且对数学要求很高。希望大家好运，在面试的时候不要遇到这种题目。。。
    */
    int movesToChessboard(vector<vector<int>>& board) {
        int N = board.size(), rowSum = 0, colSum = 0, rowSwap = 0, colSwap = 0;
        //这是一个很强烈的条件，内部的四个角组合只能是 1111，0000，和1100的乱序
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (board[0][0] ^ board[i][0] ^ board[0][j] ^ board[i][j]) {
                    return -1;
                }
            }
        }
        for (int i = 0; i < N; ++i) {//求出行和列的1的个数
            rowSum += board[0][i];
            colSum += board[i][0];
            rowSwap += board[i][0] == i % 2;//这个没关系，我们一会会用最小值
            colSwap += board[0][i] == i % 2;
        }
        if (N / 2 > rowSum || rowSum > (N + 1) / 2) {
            return -1;
        }
        if (N / 2 > colSum || colSum > (N + 1) / 2) {
            return -1;
        }
        if (N % 2) {
            if (colSwap % 2) {
                colSwap = N - colSwap;
            }
            if (rowSwap % 2) {
                rowSwap = N - rowSwap;
            }
        }
        else {
            colSwap = min(N - colSwap, colSwap);
            rowSwap = min(N - rowSwap, rowSwap);
        }
        return (colSwap + rowSwap) / 2;
    }
};

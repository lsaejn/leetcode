//
// On an NxN chessboard, a knight starts at the r-th row and c-th column and attempts to make exactly K moves.  The rows and columns are 0 indexed, so the top-left square is (0, 0), and the bottom-right square is (N-1, N-1).
//
//
//
// A chess knight has 8 possible moves it can make, as illustrated below.  Each move is two squares in a cardinal direction, then one square in an orthogonal direction.
//
//
//
//
//
// Each time the knight is to move, it chooses one of eight possible moves uniformly at random (even if the piece would go off the chessboard) and moves there.
//
//
//
// The knight continues moving until it has made exactly K moves or has moved off the chessboard.  Return the probability that the knight remains on the board after it has stopped moving.
//
//
// Example:
//
// Input: 3, 2, 0, 0
// Output: 0.0625
// Explanation: There are two moves (to (1,2), (2,1)) that will keep the knight on the board.
// From each of those positions, there are also two moves that will keep the knight on the board.
// The total probability the knight stays on the board is 0.0625.
//
//
//
// Note:
// N will be between 1 and 25.
// K will be between 0 and 100.
// The knight always initially starts on the board.
//


class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        N = N + 4;
        r = r + 2;
        c = c + 2;
        double cnt = 0;
        vector<vector<double>> board(N,vector<double>(N,0));
        vector<vector<double>> cur(N,vector<double>(N,0));
        board[r][c] = 1;
        for(int i = 0;i < K;++i){
            for(int j = 2;j < N-2;++j){
                for(int k = 2;k < N-2;++k){
                    cur[j][k] = board[j-1][k+2] + board[j-1][k-2] + board[j+1][k+2] + board[j+1][k-2] + 
                                  board[j-2][k+1] + board[j-2][k-1] + board[j+2][k+1] + board[j+2][k-1];
                }
            }
            board = cur;
        }
        for(int j = 2;j < N-2;++j)
            for(int k = 2;k < N-2;++k)
                cnt += board[j][k];
        double base = pow(8,K);
        return cnt / base;
    }
};

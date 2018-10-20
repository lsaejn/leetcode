// A robot on an infinite grid starts at point (0, 0) and faces north.  The robot can receive one of three possible types of commands:
//
//
// 	-2: turn left 90 degrees
// 	-1: turn right 90 degrees
// 	1 <= x <= 9: move forward x units
//
//
// Some of the grid squares are obstacles. 
//
// The i-th obstacle is at grid point (obstacles[i][0], obstacles[i][1])
//
// If the robot would try to move onto them, the robot stays on the previous grid square instead (but still continues following the rest of the route.)
//
// Return the square of the maximum Euclidean distance that the robot will be from the origin.
//
//  
//
// Example 1:
//
//
// Input: commands = [4,-1,3], obstacles = []
// Output: 25
// Explanation: robot will go to (3, 4)
//
//
//
// Example 2:
//
//
// Input: commands = [4,-1,4,-2,4], obstacles = [[2,4]]
// Output: 65
// Explanation: robot will be stuck at (1, 4) before turning left and going to (1, 8)
//
//
//
//  
//
// Note:
//
//
// 	0 <= commands.length <= 10000
// 	0 <= obstacles.length <= 10000
// 	-30000 <= obstacle[i][0] <= 30000
// 	-30000 <= obstacle[i][1] <= 30000
// 	The answer is guaranteed to be less than 2 ^ 31.
//


class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) 
    {
        int max = 0;
        vector<pair<int,int>> dx = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};//顺时针
        int k = 0;//方向，0
        map<pair<int,int>, bool> col;
        for (int i = 0; i < obstacles.size(); i++) 
            col.insert(make_pair(make_pair(obstacles[i][0],obstacles[i][1]),true));
        int p = 0, q = 0;
        for (int command : commands)
        {
            if (command == -1) 
                k = (k + 1) % 4;
            else if (command == -2)
                k = (k + 4 - 1) % 4;
            else 
            {
                pair<int,int> cur = dx[k];
                for (int i = 0; i < command; i++) 
                {
                    if (col[make_pair(p + cur.first,q + cur.second)]==true)
                    {
                        break;
                    }
                    p += cur.first;
                    q += cur.second;
                }
                max =std::max(max, p * p + q * q);
            }
        }
        return max;
    }
};

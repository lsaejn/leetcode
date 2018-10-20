// In a row of seats, 1 represents a person sitting in that seat, and 0 represents that the seat is empty. 
//
// There is at least one empty seat, and at least one person sitting.
//
// Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized. 
//
// Return that maximum distance to closest person.
//
//
// Example 1:
//
//
// Input: [1,0,0,0,1,0,1]
// Output: 2
// Explanation: 
// If Alex sits in the second open seat (seats[2]), then the closest person has distance 2.
// If Alex sits in any other open seat, the closest person has distance 1.
// Thus, the maximum distance to the closest person is 2.
//
//
// Example 2:
//
//
// Input: [1,0,0,0]
// Output: 3
// Explanation: 
// If Alex sits in the last seat, the closest person is 3 seats away.
// This is the maximum distance possible, so the answer is 3.
//
//
// Note:
//
//
// 	1 <= seats.length <= 20000
// 	seats contains only 0s or 1s, at least one 0, and at least one 1.
//
//
//


class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        vector<int> new_seats;//左右两边都算成1，统一规划
        new_seats.push_back(1);
        for(int i=0;i<seats.size();i++)
            new_seats.push_back(seats[i]);
        new_seats.push_back(1);
 
        int max_jiange=-1,temp=0;//求出最大的连续0长度
        for(int i=0;i<new_seats.size();i++)
        {
            if(new_seats[i]==0)
                temp++;
            else
            {
                max_jiange = max(max_jiange,temp);
                temp = 0;
            }
        }
        
        if(seats[0]!=0 && seats[seats.size()-1]!=0)//不涉及到可能是坐在两头的情况
            return int((max_jiange+1)/2);
        else
        {
            int left_maxlen=0,right_maxlen=0;
            int pos=0;
            while(seats[pos]==0)    {pos++;left_maxlen++;}
            pos=seats.size()-1;
            while(seats[pos]==0)    {pos--;right_maxlen++;}
            return max(int((max_jiange+1)/2),max(left_maxlen,right_maxlen));
        }
    }
};

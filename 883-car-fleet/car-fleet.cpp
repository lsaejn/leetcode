// N cars are going to the same destination along a one lane road.  The destination is target miles away.
//
// Each car i has a constant speed speed[i] (in miles per hour), and initial position position[i] miles towards the target along the road.
//
// A car can never pass another car ahead of it, but it can catch up to it, and drive bumper to bumper at the same speed.
//
// The distance between these two cars is ignored - they are assumed to have the same position.
//
// A car fleet is some non-empty set of cars driving at the same position and same speed.  Note that a single car is also a car fleet.
//
// If a car catches up to a car fleet right at the destination point, it will still be considered as one car fleet.
//
//
// How many car fleets will arrive at the destination?
//
//  
//
// Example 1:
//
//
// Input: target = 12, position = [10,8,0,5,3], speed = [2,4,1,1,3]
// Output: 3
// Explanation:
// The cars starting at 10 and 8 become a fleet, meeting each other at 12.
// The car starting at 0 doesn't catch up to any other car, so it is a fleet by itself.
// The cars starting at 5 and 3 become a fleet, meeting each other at 6.
// Note that no other cars meet these fleets before the destination, so the answer is 3.
//
//
//
// Note:
//
//
// 	0 <= N <= 10 ^ 4
// 	0 < target <= 10 ^ 6
// 	0 < speed[i] <= 10 ^ 6
// 	0 <= position[i] < target
// 	All initial positions are different.
//



    //我们从后向前遍历，
    //1.每个车都是1个车队，n+1,后面的车i计算自己前面的车到达终点的时间t，看自己是不是能在t之内追上i-1
    //若能，是一个车队,车队数-1
    //如果前方已没有车队，显然不--
class Solution
{
private:
    bool catchup(long p1, long s1, long p2, long s2, long target) 
    {
        return (target - p1) * s2 <= (target - p2) * s1;
    }
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) 
    {
        if (position.empty()) return 0;

        int n = position.size();
        vector<pair<int, int>> items;
        for (int i = 0; i < n; ++i) 
            items.push_back(make_pair(position[i], speed[i]));
        sort(items.begin(), items.end());//以位置排序，0，3，5，8，10

        int res = 1;//这个是反向思考，第一个车是1个车队，如果它无法被追赶，
        int curfleet = n - 1;
        for (int i = n - 2; i >= 0; --i)
        {
            if (!catchup(items[i].first, items[i].second, items[curfleet].first, items[curfleet].second, target)) 
            {
                ++res;
                curfleet = i;
            }
        }

        return res;
    }
};


// The i-th person has weight people[i], and each boat can carry a maximum weight of limit.
//
// Each boat carries at most 2 people at the same time, provided the sum of the weight of those people is at most limit.
//
// Return the minimum number of boats to carry every given person.  (It is guaranteed each person can be carried by a boat.)
//
//  
//
//
// Example 1:
//
//
// Input: people = [1,2], limit = 3
// Output: 1
// Explanation: 1 boat (1, 2)
//
//
//
// Example 2:
//
//
// Input: people = [3,2,2,1], limit = 3
// Output: 3
// Explanation: 3 boats (1, 2), (2) and (3)
//
//
//
// Example 3:
//
//
// Input: people = [3,5,3,4], limit = 5
// Output: 4
// Explanation: 4 boats (3), (3), (4), (5)
//
// Note:
//
//
// 	1 <= people.length <= 50000
// 	1 <= people[i] <= limit <= 30000
//
//
//
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //思路是这样，排序，然后放人，比如 1，2，3，3，4，5，6 limit=7
    //{6} {5},{4,3},{3,2,1}
    //一直超时，检查了半天，原来忘了注释copy
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.rbegin(),people.rend());
        //copy(people.begin(),people.end(),std::ostream_iterator<int>(std::cout, " "));
        map<int,int> col;//缺口数
        int result=0;
        for(int i=0;i!=people.size();++i)
        {
            int freeSize=limit-people[i];//放入本元素，船还剩多少freeSize
            if(freeSize<people.back())
            {
                result++;
                continue;
            }
            //接下来freeSize>0
            auto iter=col.lower_bound(people[i]);
            if(iter==col.end())//找不到
            {
                result++;
                col[freeSize]++;
            }
            else
            {
                if(1==iter->second--)
                    col.erase(iter);
            }          
        }
        return result;
        
    }
};

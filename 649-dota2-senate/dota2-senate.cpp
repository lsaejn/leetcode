//
// In the world of Dota2, there are two parties: the Radiant and the Dire.
//
//
//
// The Dota2 senate consists of senators coming from two parties. Now the senate wants to make a decision about a change in the Dota2 game. The voting for this change is a round-based procedure. In each round, each senator can exercise one of the two rights:
//
// Ban one senator's right: A senator can make another senator lose all his rights in this and all the following rounds.
// Announce the victory: If this senator found the senators who still have rights to vote are all from the same party, he can announce the victory and make the decision about the change in the game.
//
//
//
//
// Given a string representing each senator's party belonging. The character 'R' and 'D' represent the Radiant party and the Dire party respectively. Then if there are n senators, the size of the given string will be n.
//
//
//
// The round-based procedure starts from the first senator to the last senator in the given order. This procedure will last until the end of voting. All the senators who have lost their rights will be skipped during the procedure.
//
//
//
// Suppose every senator is smart enough and will play the best strategy for his own party, you need to predict which party will finally announce the victory and make the change in the Dota2 game. The output should be Radiant or Dire.
//
//
// Example 1:
//
// Input: "RD"
// Output: "Radiant"
// Explanation: The first senator comes from Radiant and he can just ban the next senator's right in the round 1. And the second senator can't exercise any rights any more since his right has been banned. And in the round 2, the first senator can just announce the victory since he is the only guy in the senate who can vote.
//
//
//
//
// Example 2:
//
// Input: "RDD"
// Output: "Dire"
// Explanation: 
// The first senator comes from Radiant and he can just ban the next senator's right in the round 1. And the second senator can't exercise any rights anymore since his right has been banned. And the third senator comes from Dire and he can ban the first senator's right in the round 1. And in the round 2, the third senator can just announce the victory since he is the only guy in the senate who can vote.
//
//
//
// Note:
//
// The length of the given string will in the range [1, 10,000].
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //很简单的题。但这个解法太巧妙了。
    //分成两个队列，分别拿出最小索引来比，靠前的重新放回队列尾部参与下一轮，靠后的pop
    //放回的元素下一次的投票顺序(索引)变成了index+len
string predictPartyVictory(string senate) {
        queue<int> q1, q2;
        int n = senate.length();
        for(int i = 0; i<n; i++)
            (senate[i] == 'R')?q1.push(i):q2.push(i);
        while(!q1.empty() && !q2.empty()){
            int r_index = q1.front(), d_index = q2.front();
            q1.pop(), q2.pop();
            (r_index < d_index)?q1.push(r_index + n):q2.push(d_index + n);
        }
        return (q1.size() > q2.size())? "Radiant" : "Dire";
    }
};

//
// You have a lock in front of you with 4 circular wheels.  Each wheel has 10 slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'.  The wheels can rotate freely and wrap around: for example we can turn '9' to be '0', or '0' to be '9'.  Each move consists of turning one wheel one slot.
//
// The lock initially starts at '0000', a string representing the state of the 4 wheels.
//
// You are given a list of deadends dead ends, meaning if the lock displays any of these codes, the wheels of the lock will stop turning and you will be unable to open it.
//
// Given a target representing the value of the wheels that will unlock the lock, return the minimum total number of turns required to open the lock, or -1 if it is impossible.
//
//
// Example 1:
//
// Input: deadends = ["0201","0101","0102","1212","2002"], target = "0202"
// Output: 6
// Explanation:
// A sequence of valid moves would be "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202".
// Note that a sequence like "0000" -> "0001" -> "0002" -> "0102" -> "0202" would be invalid,
// because the wheels of the lock become stuck after the display becomes the dead end "0102".
//
//
//
// Example 2:
//
// Input: deadends = ["8888"], target = "0009"
// Output: 1
// Explanation:
// We can turn the last wheel in reverse to move from "0000" -> "0009".
//
//
//
// Example 3:
//
// Input: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"
// Output: -1
// Explanation:
// We can't reach the target without getting stuck.
//
//
//
// Example 4:
//
// Input: deadends = ["0000"], target = "8888"
// Output: -1
//
//
//
// Note:
//
// The length of deadends will be in the range [1, 500].
// target will not be in the list deadends.
// Every string in deadends and the string target will be a string of 4 digits from the 10,000 possibilities '0000' to '9999'.
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<string> myQue;
        unordered_set<string> dde(deadends.begin(),deadends.end());
        if(dde.count("0000"))
            return -1;
        myQue.push("0000");
        int queSize=1;
        int layer=0;
        int i,j;
        string temp,temp1;
        unordered_set<string> mySet;
        mySet.insert("0000");
        while(!myQue.empty()){
            layer++;
            queSize=myQue.size();
            for(i=0;i<queSize;i++){
                temp=myQue.front();
                for(j=0;j<4;j++){
                    temp1=temp;//add
                    if(temp1[j]=='9')
                        temp1[j]='0';
                    else
                        temp1[j]+=1;
                    if(temp1==target)
                        return layer;
                    if(!dde.count(temp1)&&!mySet.count(temp1)){            
                            myQue.push(temp1);
                            mySet.insert(temp1);                            
                    }
                    temp1=temp;//sub
                    if(temp1[j]=='0')
                        temp1[j]='9';
                    else
                        temp1[j]-=1;
                    if(temp1==target)
                        return layer;
                    if(!dde.count(temp1)&&!mySet.count(temp1)){
                            myQue.push(temp1);
                            mySet.insert(temp1);                   
                    }
                }
                myQue.pop(); 
            }
        }
        return -1;  

    }
};

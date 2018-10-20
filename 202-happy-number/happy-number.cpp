// Write an algorithm to determine if a number is "happy".
//
// A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
//
// Example: 
//
//
// Input: 19
// Output: true
// Explanation: 
// 12 + 92 = 82
// 82 + 22 = 68
// 62 + 82 = 100
// 12 + 02 + 02 = 1
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    bool isHappy(int n) {
        vector<int> vec(10);
        while(n!=1)
        {
            if(n<=4)//4 16 37 9+49=58 25+64 89 72+81 153 1+25+9 35 9+25=34 9+16=25 29 85 64+25=89 64+81 145 1+16+25 42 16+4=20 4
                return false;
            while(n)
            {
                int m=n%10;
               vec.push_back(m); 
                n=n/10;               
            }
            int sum=0;
            for(int i=0;i<vec.size();++i)
                sum+=vec[i]*vec[i];
            n=sum;
            vec.clear();

        }
        return true;
        
    }
};

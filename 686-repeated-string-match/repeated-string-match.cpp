// Given two strings A and B, find the minimum number of times A has to be repeated such that B is a substring of it. If no such solution, return -1.
//
// For example, with A = "abcd" and B = "cdabcdab".
//
// Return 3, because by repeating A three times (“abcdabcdabcd”), B is a substring of it; and B is not a substring of A repeated two times ("abcdabcd").
//
// Note:
// The length of A and B will be between 1 and 10000.
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public://abcd cdabcdab
    //abcdefg gabcdefga
    //aab       aabaab
    //abb       abba
    //aabb  bbaa
    //aabb abbaabba
    //ccccdabc  abcc
    int repeatedStringMatch(string A, string B) {
        //先做一个假设，如果A.size()>B.size()，那么前后都拼接一次就完了，拼不出来肯定也没用。也就是2次
        //我们先把A扩展到超过B再说，这样才能判断。这需要B.size()/A.size()次.比如size为3，8 需要拼接3次，i=1,3;i=2,6;i=3;9;
        //如果不行，前后再拼接一次，进入到假设1      
        string t = A;
        for (int i = 1; i <= B.size() / A.size() +1+ 2; ++i)//原解是+2，反正和我的理解可能不一样
        {
            if (t.find(B) != string::npos) 
                return i;
            t += A;
        }
        return -1;
        
    }
};

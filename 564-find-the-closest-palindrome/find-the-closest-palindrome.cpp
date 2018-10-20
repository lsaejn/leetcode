// Given an integer n, find the closest integer (not including itself), which is a palindrome. 
//
// The 'closest' is defined as absolute difference minimized between two integers.
//
// Example 1:
//
// Input: "123"
// Output: "121"
//
//
//
// Note:
//
// The input n is a positive integer represented by string, whose length will not exceed 18.
// If there is a tie, return the smaller one as answer.
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    string makePalindromic(string s) 
    {
        for (int i = 0, j = (int)s.length() - 1; i < j; i++, j--)
            s[j] = s[i];
        return s;
    }
    //这种题基本上是怼测试用例怼出来的。
    //1-10 n-1
    //11 9
    //12-11
    //13-11
    //14-11
    //15-11
    //16-11
    //17-22
    //18-22
    //19-22
    //20-22
    //22-11/
    //我跑了很多数字，基本上是12345->12321这种。所以我们优先构造12321,
    //但是也有例外，比如12321->12221,其次靠近的显然是12421,可见只要改动对称的最后一位就可以了，把对称位-1,然后看看有没有例外。
    //12021->12121,很快发现了例外，那么我们把对称位+1即可
    //真的是这样吗？例外呢？见14，减1之后第一位数变成了0，我们需要的是产生10，然后+-1
    //
    string nearestPalindromic(string n) {//11
        if (n == "0") return "1";
        
        long long orgVal = stoll(n);
    
        // candidate #1 (ex: 123xx -> 12321, 123xxx -> 123321)
        string res = makePalindromic(n);
        long long resVal = stoll(res);//11
        long long diff = abs(resVal - orgVal);//0
    
        long long scale = (long long)pow(10, (int)n.length() / 2);//10
    
        // candidate #2 (ex: 123xx -> 12221, 123xxx -> 122221, 100xx -> 9999)
        string smaller = makePalindromic(to_string((orgVal / scale) * scale - 1));//9
        // candidate #3 (ex: 123xx -> 12421, 123xxx -> 124421, 99xx -> 10001)
        string bigger = makePalindromic(to_string((orgVal / scale) * scale + scale));

        long long smallerVal = stoll(smaller);
        if (diff == 0 || abs(orgVal - smallerVal) <= diff) {
            res = smaller;
            diff = abs(orgVal - smallerVal);
        }

        long long biggerVal = stoll(bigger);
        if (abs(orgVal - biggerVal) < diff)
            res = bigger;
    
        return res;
    }
};

// Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
//
// Example 1:
//
//
// Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
// Output: true
//
//
// Example 2:
//
//
// Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
// Output: false
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //建议画图，因为多出一个长度
/*dp  abc aab aabcab
 dp   0  1 2 3
 dp   '' a b a
0 ''  y  y n n
1 a   y  y 
2 a   y
3 b   n
*/    
 bool isInterleave(string s1, string s2, string s3) {
    
    if(s3.length() != s1.length() + s2.length())
        return false;
    
    bool table[s1.length()+1][s2.length()+1];
    //table[i][j] s1的索引i之前的元素能不能和s2索引j之前的元素拼出s[0]...s[i+j-1]
    /*
    因为我们多加了一个长度所以table[0][0]=true,可以想象成空串必然拼出空串。当然也可以拿公式凑。这样i和j变成了当前s1参与匹配的字符串长度。
    i+j就是应该匹配的s3长度，最后的索引显然是[i+j-1]
    然后我们后推导
    存在两个情况:
    如果最后一个元素s1[i-1]=s3[i+j-1],则结果取决于table[i-1][j]
    另一个也是如此。
    */
    for(int i=0; i<s1.length()+1; i++)
        for(int j=0; j< s2.length()+1; j++)
        {
            if(i==0 && j==0)//空串必然可以
                table[i][j] = true;
            else if(i == 0)
                table[i][j] = ( table[i][j-1] && s2[j-1] == s3[i+j-1]);
            else if(j == 0)
                table[i][j] = ( table[i-1][j] && s1[i-1] == s3[i+j-1]);
            else
                table[i][j] = (table[i-1][j] && s1[i-1] == s3[i+j-1] ) || (table[i][j-1] && s2[j-1] == s3[i+j-1] );
        }
        
    return table[s1.length()][s2.length()];
}
};

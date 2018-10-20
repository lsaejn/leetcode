// Given a string S and a string T, count the number of distinct subsequences of S which equals T.
//
// A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
//
// Example 1:
//
//
// Input: S = "rabbbit", T = "rabbit"
// Output: 3
// Explanation:
//
// As shown below, there are 3 ways you can generate "rabbit" from S.
// (The caret symbol ^ means the chosen letters)
//
// rabbbit
// ^^^^ ^^
// rabbbit
// ^^ ^^^^
// rabbbit
// ^^^ ^^^
//
//
// Example 2:
//
//
// Input: S = "babgbag", T = "bag"
// Output: 5
// Explanation:
//
// As shown below, there are 5 ways you can generate "bag" from S.
// (The caret symbol ^ means the chosen letters)
//
// babgbag
// ^^ ^
// babgbag
// ^^    ^
// babgbag
// ^    ^^
// babgbag
//   ^  ^^
// babgbag
//     ^^^
//
//


class Solution {
public:
    //我们准备一个dp从前向后统计当前一共出现过多少t里的字符即可
    /*比如S = "babgbag", T = "bag"
        b  a  b  g  b  a  g
    b   1  0  1  0  1  0  0
    a   0  1  0  0  0  1  0
    g   0  0  0  1  0  0  1
    
    开始dp,代表到以当前位置为结尾的目标字符,
    比如ba,需要一个辅助变量记录当前出现多少b  

    ba  0  1  0  0  0  3  0
    bag 0  0  0  1  0  0  1 
     比如bag,需要一个辅助变量记录当前出现多少ba
        b  a  b  g  b  a  g
    b   1  0  1  0  1  0  0
    ba  0  1  0  0  0  3  0
    bag 0  0  0  1  0  0  4 
    
    然后从下向上,从右向左遍历，当出现0，就可以结束了
    g=2 说明两个g,g=2,查询上面，发现a=2,b=3,说明g的左边2个a，
    */
    //最终可以简化成一个数组+一个变量，分别用于记录上一层字符出现的累计个数，和目前已经符合条件的个数即可
    //比如
    /*
        b  a  b  g  b  a  g
    b   1  1  2  2  3  3  3  
    
        b  a  b  g  b  a  g
    ba  0  1  1  1  1  3  0
    cnt=0  1  1  1  1  4  4
    
        b  a  b  g  b  a  g
    bag 0  0  0  1  1  1  4
    cnt=0  0  0  1  1  1  5
    
    
    
*/
int numDistinct(string s, string t) {
    if(t.size() < 1 || s.size() < 1)
        return 0;
    
    int dp[t.size()][s.size()];
    memset(dp, 0, sizeof(dp));
    
    //matching same character 
    for(int i=0; i<t.size(); i++)
        for(int j=0; j<s.size(); j++)
            if( t[i] == s[j] )
                dp[i][j]=1;
    
    //DP step
    for(int i=1; i<t.size(); i++)
    {
        for(int j=0, cnt=0; j<s.size(); j++)
        {
            
            if( dp[i][j]==1 )
                dp[i][j]=cnt;
            cnt+=dp[i-1][j];
        }
    }

   
    //sum last row
    int result = 0;
    for(int j=0; j<s.size(); j++)
        result +=  dp[t.size()-1][j];
    return result;
}
};

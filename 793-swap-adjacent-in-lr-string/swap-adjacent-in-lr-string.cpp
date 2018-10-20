// In a string composed of 'L', 'R', and 'X' characters, like "RXXLRXRXL", a move consists of either replacing one occurrence of "XL" with "LX", or replacing one occurrence of "RX" with "XR". Given the starting string start and the ending string end, return True if and only if there exists a sequence of moves to transform one string to the other.
//
// Example:
//
//
// Input: start = "RXXLRXRXL", end = "XRLXXRRLX"
// Output: True
// Explanation:
// We can transform start to end following these steps:
// RXXLRXRXL ->
// XRXLRXRXL ->
// XRLXRXRXL ->
// XRLXXRRXL ->
// XRLXXRRLX
//
//
// Note:
//
//
// 	1 <= len(start) = len(end) <= 10000.
// 	Both start and end will only consist of characters in {'L', 'R', 'X'}.
//


class Solution {
public:
    //因为RX..XL可以变成X...XRL，R可以移动时都忽略X,而不能移动时，X不造成影响
    //这个事实就是X可以忽略掉，反正RXXXL不关心X的位置 视为RL是可以的，因为RL肯定不能换位置。RL无法转换成LR
    /*
    L可以后退，R可以前进
*/
    bool canTransform(string start, string end) {
        int n=start.size();
        assert(n == end.size());
        int lcnt = 0, rcnt = 0;
        for(int i=0;i<n;i++)//检查LR数量
        {
            if(start[i] == 'L') ++lcnt;
            else if(start[i] == 'R') ++rcnt;
            if(end[i] == 'L') --lcnt;
            else if(end[i] == 'R') --rcnt;
        }
        if(lcnt || rcnt) return false;
        
        int i=0,j=0;//两个游标
        while(j < n && i < n)
        {
            //跳过X
            while(j < n && end[j] == 'X') ++j;
            while(i < n && start[i] == 'X') ++i;
            if(i==n&&j==n) break;//到头了仍没有LR出现
            if(i==n || j==n || start[i] != end[j]) return false;//只一个到头了错误。双方符号不同，错误。
            //进行到这里，说明前面都匹配了。我们只要看start的R能不能右移到后面(i<j),L是不是
            if(start[i] == 'R' && i > j) return false;//当前为R，但指向非X的j在前面，即...XXXR/...XLXX,无论如何也无法左移
            else if(start[i] == 'L' && i < j) return false;//当前为L，但指向非X的j在后面，即...LXXX/...XXXL,无论如何也无法左移
            ++i; ++j;
        }
        
        return true;
    }
};

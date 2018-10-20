// Alice has a hand of cards, given as an array of integers.
//
// Now she wants to rearrange the cards into groups so that each group is size W, and consists of W consecutive cards.
//
// Return true if and only if she can.
//
//  
//
//
//
//
// Example 1:
//
//
// Input: hand = [1,2,3,6,2,3,4,7,8], W = 3
// Output: true
// Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8].
//
// Example 2:
//
//
// Input: hand = [1,2,3,4,5], W = 4
// Output: false
// Explanation: Alice's hand can't be rearranged into groups of 4.
//
//  
//
// Note:
//
//
// 	1 <= hand.length <= 10000
// 	0 <= hand[i] <= 10^9
// 	1 <= W <= hand.length
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:   
    //如果能整除的话，需要对数组进行排序，然后判断每组的的数数的差是否为1，那不多说了，排序时间复杂度为o(nlongn)， 判断的时间复杂度为o(n)，则时间复杂度为o(nlongn)
    bool isNStraightHand(vector<int>& hand, int W) {
        long len = hand.size();
        if(len == 1 || W == 1)
            return true;
        if(len % W != 0)
            return false;
        sort(hand.begin(), hand.end());   
        vector<int> visit(len);
        for(int i = 0; i < len; i++)
        {
            if(!visit[i]){
                int cnt = W - 1;
                visit[i] = 1;
                int x = hand[i];
                int j = i;
                while(cnt){
                    if(j < len){ 
                        if(hand[j] != x){
                            if(!visit[j]){
                                if(hand[j] - x == 1){
                                    x = hand[j];
                                    visit[j] = 1;
                                    cnt--;
                                }
                            }        
                        }
                    }
                    else if(j == len + 1)
                        return false;
                    j++;
                }
            }
        }
        return true;
    }
};

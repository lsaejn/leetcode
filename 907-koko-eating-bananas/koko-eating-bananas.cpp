// Koko loves to eat bananas.  There are N piles of bananas, the i-th pile has piles[i] bananas.  The guards have gone and will come back in H hours.
//
// Koko can decide her bananas-per-hour eating speed of K.  Each hour, she chooses some pile of bananas, and eats K bananas from that pile.  If the pile has less than K bananas, she eats all of them instead, and won't eat any more bananas during this hour.
//
// Koko likes to eat slowly, but still wants to finish eating all the bananas before the guards come back.
//
// Return the minimum integer K such that she can eat all the bananas within H hours.
//
//  
//
//
//
//
//
// Example 1:
//
//
// Input: piles = [3,6,7,11], H = 8
// Output: 4
//
//
//
// Example 2:
//
//
// Input: piles = [30,11,23,4,20], H = 5
// Output: 30
//
//
//
// Example 3:
//
//
// Input: piles = [30,11,23,4,20], H = 6
// Output: 23
//
//
//  
//
// Note:
//
//
// 	1 <= piles.length <= 10^4
// 	piles.length <= H <= 10^9
// 	1 <= piles[i] <= 10^9
//
//
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


typedef long long int64;
class Solution {
public:
    int minEatingSpeed(vector<int>& a, int H)
    {
        int n = a.size();
        int low = 1, high = *max_element(a.begin(), a.end());
        while (low != high) 
        {
            int mid = (low + high) / 2;//以mid作为速度
            int64 sum = 0;
            for (int i = 0; i < n; ++i) 
               // sum += (a[i] + mid - 1) / mid;
            {
                sum += ceil(a[i]*1.0/mid);
                //cout<<
            }
            //cout<<sum<<endl;
            if (sum > H) 
                low = mid + 1;
            else 
                high = mid;
        }
        return high;
    }
};

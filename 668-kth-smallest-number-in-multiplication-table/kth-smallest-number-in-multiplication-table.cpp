//
// Nearly every one have used the Multiplication Table. But could you find out the k-th smallest number quickly from the multiplication table?
//
//
//
// Given the height m and the length n of a m * n Multiplication Table, and a positive integer k, you need to return the k-th smallest number in this table.
//
//
// Example 1:
//
// Input: m = 3, n = 3, k = 5
// Output: 
// Explanation: 
// The Multiplication Table:
// 1	2	3
// 2	4	6
// 3	6	9
//
// The 5-th smallest number is 3 (1, 2, 2, 3, 3).
//
//
//
//
// Example 2:
//
// Input: m = 2, n = 3, k = 6
// Output: 
// Explanation: 
// The Multiplication Table:
// 1	2	3
// 2	4	6
//
// The 6-th smallest number is 6 (1, 2, 2, 3, 4, 6).
//
//
//
//
// Note:
//
// The m and n will be in the range [1, 30000].
// The k will be in the range [1, m * n]
//
//


//难度在于计算比x小的数有多少个。实际上除一下就行了。
//比如6.在第一行，比6小的
//然后有个陷阱。测试用例42,34,401,如果用二分查找，会找到127
//这个数不存在于乘法表里。当cnt==k时，我们应该把它作为右边界。然后让左边界去检验它
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int left = 1, right = m * n;
        while (left < right) {
            int mid = left + (right - left) / 2, cnt = 0;
            for (int i = 1; i <= m; ++i) {
                cnt += (mid / i <= n) ? (mid / i) : n;
            }
            if (cnt < k) left = mid + 1;
            //else if (cnt==k)  return mid;
            else right = mid;
        }
        return left;
    }
};

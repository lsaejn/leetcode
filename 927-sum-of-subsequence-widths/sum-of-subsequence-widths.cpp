// Given an array of integers A, consider all non-empty subsequences of A.
//
// For any sequence S, let the width of S be the difference between the maximum and minimum element of S.
//
// Return the sum of the widths of all subsequences of A. 
//
// As the answer may be very large, return the answer modulo 10^9 + 7.
//
//
//  
//
// Example 1:
//
//
// Input: [2,1,3]
// Output: 6
// Explanation:
// Subsequences are [1], [2], [3], [2,1], [2,3], [1,3], [2,1,3].
// The corresponding widths are 0, 0, 0, 1, 1, 2, 2.
// The sum of these widths is 6.
//
//
//  
//
// Note:
//
//
// 	1 <= A.length <= 20000
// 	1 <= A[i] <= 20000
//
//
//


/*
思路有两个
1.我们用一个dp来保存i,j的最大最小值。然后构建子序列统计
2.用两个优先队列        
*/
//那么基本的问题是如何有效的构建子序列
//我的方法是这样，先放2，整体拷贝再添加，过程如下
//2->  2，1，1/2->  2,1,1/2,3,2/3,1/3,1/2/3
/*我们发现，每次添加的时候，新元素都占了一半，这是显然的结论，因为新元素是复制一份之前
的元素,然后在集合里添加自己，然后一个只含自己的集合，这刚好使得每次拷贝，每个元素都均等地出现在所有集合里
//比如上面，第3次添加时，2,1,3三个元素都出现在了了4个集合
//3出现的集合占了1/2，而3没出现的集合里，2占了1/2;
//我们只要求距离，所以放入的先后没有关系。wow，答案呼之欲出
//我们排序，显然一共有s(n)=2^(n-1)+n*(n-1)/2项
//最大值占1/2，这些里面，含最小值里的有1/2，不含最小值的含次小值又占1/2,
//所以我们排序求和，直到所含的个数只有1
*/
/*
然后大神发现了下面的方法
我们先排序.
非常巧妙，对于单个的元素，它既是最大又是最小值。让我们看看它出色在哪。
记得之前的分析吗？每个元素都占了
For A[i]:
There are i smaller numbers,
so there are 2 ^ i sequences in which A[i] is maximum.
we should do res += A[i] * (2 ^ i)

There are n - i - 1 bigger numbers,
so there are 2 ^ (n - i - 1) sequences in which A[i] is minimum.
we should do res -= A[i] * 2 ^ (n - i - 1)
*/
const int mod=1000000007;
class Solution {
public:
    int sumSubseqWidths(vector<int> A) 
    {
        sort(A.begin(), A.end());
        long c = 1, res = 0;
        for (int i = 0; i < A.size(); ++i)
        //A[i]
        {
            res = (res + A[i] * c - A[A.size() - i - 1] * c) % mod;//
            //cout<<res<<"  ";
            c = (c*2) % mod;
        }
        return res ;
    }
};

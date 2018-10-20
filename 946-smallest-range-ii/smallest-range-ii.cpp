// Given an array A of integers, for each integer A[i] we need to choose either x = -K or x = K, and add x to A[i] (only once).
//
// After this process, we have some array B.
//
// Return the smallest possible difference between the maximum value of B and the minimum value of B.
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
// Input: A = [1], K = 0
// Output: 0
// Explanation: B = [1]
//
//
//
// Example 2:
//
//
// Input: A = [0,10], K = 2
// Output: 6
// Explanation: B = [2,8]
//
//
//
// Example 3:
//
//
// Input: A = [1,3,6], K = 3
// Output: 3
// Explanation: B = [4,6,3]
//
//
//  
//
// Note:
//
//
// 	1 <= A.length <= 10000
// 	0 <= A[i] <= 10000
// 	0 <= K <= 10000
//
//
//
//
//


//left是所有数+K的最小值，left首先就不应该-K,这显然没有意义，只会让最小值更小。同理right是所有数-K的最大值，再加只会让最大值更大。
//然后我们从前向后遍历。目的是在左边求出最大值，在右边求出最小值
//那么，怎么更新新的最大值呢？很简单A[i]+K，这样来尝试得到新的最大值。我们只想增大A[i],使得最大值更大
//同时还要更新最小值.怎么更新新的最小值呢？新的最小值最可能就是出现在自己右边，因为右边要减去K,且是离自己最近的数
//你可能会怀疑，比如K=3,A={1 30 31 100},难道30和31组得出最佳结果吗？
//显然，它还应该受边界影响。你能得到的最小值是1+3,还能得到更小的？no，你想修改最小值，那么你无论怎么减K都应该比他小，而你A[i]+K一定比它大。所以最小值应该-K来取得
//同理，100-3是应该参考的最大值，所有A[i]-K不可能大于它。所以我们要让所有A[i]+K来尝试大于他。
//于是，我们开始尝试让A[i]-K,这样可以尝试获得一个最小值，根据上面的分析，它一定要比1+3小才能改变最小值。于是我们得到了Minn,于是我们还需要一个最大值。在我们的右边已经有一个可参考最大值97了。我们要检查A[i]+K是不是比它更大。那么我们应该检查i-1还是i+i呢？显然是i-1，因为A[i-1]比A[i]小,我们不应该让小的更小，让大的更大。
//然后把i改为i+1.我们需要比较A[i]+K和right,A[i+1]-K
//是的，这是贪婪算法，你要意识到对于A[i]你想成为最大值，你要比right大。尝试A[i]+K
//成为最小值，你要比left小。尝试A[i]-K
//但你不可能同时+K或-K。我们排序，得到A[i]+K和right的教大值
//然后我们尝试让它后面的数变成最小值。让两个最近的数一个+K一个-K.只要他们的结果大于left和right即可。
//例子[1,5,6,9] K=3.显然全部加K我们得到最大值8,然后left=4,right=6.
//
class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        if(A.size() <= 1) return 0;
        
        sort(A.begin(),A.end());
        
        int ans = A[A.size() - 1] - A[0];
        int right = A[A.size() - 1] - K;
        int left = A[0] + K;
        
        for(int i = 0; i < (int)A.size() - 1; i++) {
            int maxx = max(A[i] + K, right);
            int minn = min(A[i + 1] - K, left);
            ans = min(ans, maxx - minn);
        }
        return ans;
    }
};

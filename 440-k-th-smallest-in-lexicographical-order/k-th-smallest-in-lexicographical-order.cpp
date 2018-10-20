// Given integers n and k, find the lexicographically k-th smallest integer in the range from 1 to n.
//
// Note: 1 ≤ k ≤ n ≤ 109.
//
// Example:
//
// Input:
// n: 13   k: 2
//
// Output:
// 10
//
// Explanation:
// The lexicographical order is [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9], so the second smallest number is 10.
//
//
//


class Solution {
public:
    //本质是10叉树，我们不断将cur乘以10，直到超出n，然后开始cur+1,如果超出n,则跳到cur/10+1,继续下一次
    int findKthNumber(int n, int k) {
        int cur = 1;//第一个数是1
        --k;//因此还需要找k-1个数
        while (k > 0)//我们按步前行，直到第k个数
        {
            long long step = 0, first = cur, last = cur + 1;//step,计算要走的步数。我们现在要当前范围(first,last]
            //first<n，当然要乘以10，但是这一行离下一个元素还有距离呢。所以要加上这个距离
            while (first <= n)//为什么是等于n呢？因为first我们还没有走到，我们需要再加一步
            {
                step += min((long long)n + 1, last) - first;//我们先加上这个距离。n<100时比方说1离2的距离是10
                first *= 10;
                last *= 10;
            }
            if (step <= k)
            {
                ++cur;
                k -= step;
            } 
            else
            {
                cur *= 10;
                --k; 
            }
        }
        return cur;
    }
};

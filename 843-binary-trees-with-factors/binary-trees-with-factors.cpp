// Given an array of unique integers, each integer is strictly greater than 1.
//
// We make a binary tree using these integers and each number may be used for any number of times.
//
// Each non-leaf node's value should be equal to the product of the values of it's children.
//
// How many binary trees can we make?  Return the answer modulo 10 ** 9 + 7.
//
// Example 1:
//
//
// Input: A = [2, 4]
// Output: 3
// Explanation: We can make these trees: [2], [4], [4, 2, 2]
//
// Example 2:
//
//
// Input: A = [2, 4, 5, 10]
// Output: 7
// Explanation: We can make these trees: [2], [4], [5], [10], [4, 2, 2], [10, 2, 5], [10, 5, 2].
//
//  
//
// Note:
//
//
// 	1 <= A.length <= 1000.
// 	2 <= A[i] <= 10 ^ 9.
//
//



class Solution {
public:
    /*
    思路：

我们只需要构筑递推关系即可：对于A[i]，它本身就可以形成一个只有根节点的二叉树。然后从A[0]到A[i-1]进行检查，如果发现前面某个元素A[j]和A[i]/A[j]均是A[i]的因数，那么A[i]和这两个元素也可以形成父节点和两个子节点的关系，从而构成一组二叉树，其数量是以A[j]为根节点的二叉树数目乘以以A[i] / A[j]为根节点的二叉树数目。
在实现中，我们用哈希表存储已经计算过的元素所包含的二叉树个数。为了防止溢出，我们需要将返回值定义为long long，在最后再进行static_cast操作。
*/
    int numFactoredBinaryTrees(vector<int>& A) {
        unordered_map<int, long long> hash;
        sort(A.begin(), A.end());//必须要排序！！！
        long long ret = 0, mode = 1000000007;
        for (int i = 0; i < A.size(); ++i) 
        {
            hash[A[i]] = 1;                 // the tree that only contains the root
            for (int j = 0; j < i; ++j) 
            {   // try the tree that has children A[j] and A[i] / A[j]
                if (A[i] % A[j] == 0 && hash.count(A[i] / A[j]) > 0) 
                {
                    hash[A[i]] += hash[A[j]] * hash[A[i] / A[j]];
                    hash[A[i]] %= mode;
                }
            }
            ret += hash[A[i]];
            ret %= mode;
        }
        return static_cast<int>(ret);
    }
};


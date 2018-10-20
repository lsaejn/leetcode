// The set [1,2,3,...,n] contains a total of n! unique permutations.
//
// By listing and labeling all of the permutations in order, we get the following sequence for n = 3:
//
//
// 	"123"
// 	"132"
// 	"213"
// 	"231"
// 	"312"
// 	"321"
//
//
// Given n and k, return the kth permutation sequence.
//
// Note:
//
//
// 	Given n will be between 1 and 9 inclusive.
// 	Given k will be between 1 and n! inclusive.
//
//
// Example 1:
//
//
// Input: n = 3, k = 3
// Output: "213"
//
//
// Example 2:
//
//
// Input: n = 4, k = 9
// Output: "2314"
//
//


class Solution {
public:
    //http://www.cnblogs.com/grandyang/p/4358678.html
    //分析很简单，第1位上，每个数字出现(n-1)!次，取模即可，依次取模
    string getPermutation(int n, int k) 
    {
        string res;
        string num = "123456789";
        vector<int> f(n, 1);
        for (int i = 1; i < n; ++i) 
            f[i] = f[i - 1] * i;
        --k;//减1是为了从0计算索引。比如k=2时，应该落入第一区间，但2/f[2]==1。显然，我们要让0,1落在1；2，3落在2
        for (int i = n; i >= 1; --i)//从第n位放到第1位 
        {
            int j = k / f[i - 1];//落在哪个区间。对于第i位，每个数字出现f[i-1]次
            k %= f[i - 1];
            res.push_back(num[j]);//放入这个数字
            num.erase(j, 1);//删除它
        }
        return res;
    }
};

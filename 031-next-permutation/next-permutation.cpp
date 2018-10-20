// Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
//
// If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
//
// The replacement must be in-place and use only constant extra memory.
//
// Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
//
// 1,2,3 → 1,3,2
// 3,2,1 → 1,2,3
// 1,1,5 → 1,5,1
//


class Solution {
public:
    //这个规律看了半天没看懂，毕竟大家都用的封装http://www.cnblogs.com/grandyang/p/4428207.html
    void nextPermutation(vector<int>& num)
    {
        //1,2,3 4
        int i, j, n = num.size();
        for (i = n - 2; i >= 0; --i)
        {
            if (num[i + 1] > num[i]) //从右到左找到第一个降序 1　　2　　7　　4　　3　　1，也就是7
            {
                for (j = n - 1; j > i; --j) //找比i大的数
                {
                    if (num[j] > num[i]) break;
                }
                swap(num[i], num[j]);//交换
                reverse(num.begin() + i + 1, num.end());
                return;
            }
        }
        reverse(num.begin(), num.end());
        
    }
};

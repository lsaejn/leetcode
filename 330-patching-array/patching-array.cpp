// Given a sorted positive integer array nums and an integer n, add/patch elements to the array such that any number in range [1, n] inclusive can be formed by the sum of some elements in the array. Return the minimum number of patches required.
//
// Example 1:
//
//
// Input: nums = [1,3], n = 6
// Output: 1 
// Explanation:
// Combinations of nums are [1], [3], [1,3], which form possible sums of: 1, 3, 4.
// Now if we add/patch 2 to nums, the combinations are: [1], [2], [3], [1,3], [2,3], [1,2,3].
// Possible sums are 1, 2, 3, 4, 5, 6, which now covers the range [1, 6].
// So we only need 1 patch.
//
// Example 2:
//
//
// Input: nums = [1,5,10], n = 20
// Output: 2
// Explanation: The two patches can be [2, 4].
//
//
// Example 3:
//
//
// Input: nums = [1,2,2], n = 5
// Output: 0
//
//


class Solution {
public:
    //将所有数用2进制数表示即可，比如20，表示到20=16+4=0b10100,需要表示从0b00001-ob10100.
    //1-01,2-10,4-100,8,1000,16,10000,5个数可以表示1-31，没有16，只能表示1-15
    //我们从头遍历1~n
    //那么逻辑变成了这样，范围是20
    //1.我们能用1，5表示出[1，20-10]吗？
    //2.我们能用1表示出[1,20-10-5]吗？
    //算法过程：1表示范围[1,2)，5太大了(5>2无法表示2，3，4)，我们添加2，表示到[0,4),5太大了,添加4，范围[1,8),大于5了把5加上
    //范围[1,13),13大于10，把10加上，[1,23),这样我们用1,2,4,5,10表示了[1,23)
    //如果还有一个元素20呢？需要表示到50。
    //1,2,4,5,10表示了[1,23)，它可以表示[1,43],我们继续添加8即可
    int minPatches(vector<int>& nums, int n)
    {
        long miss = 1, res = 0, i = 0;
        while (miss <= n) 
        {
            if (i < nums.size() && nums[i] <= miss)
            {
                miss += nums[i++];
            } 
            else 
            {
                miss += miss;//1+1+2+4+8，右区间范围
                ++res;
            }
        }
        return res;
    }
};

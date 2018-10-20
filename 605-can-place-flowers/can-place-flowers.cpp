// Suppose you have a long flowerbed in which some of the plots are planted and some are not. However, flowers cannot be planted in adjacent plots - they would compete for water and both would die.
//
// Given a flowerbed (represented as an array containing 0 and 1, where 0 means empty and 1 means not empty), and a number n, return if n new flowers can be planted in it without violating the no-adjacent-flowers rule.
//
// Example 1:
//
// Input: flowerbed = [1,0,0,0,1], n = 1
// Output: True
//
//
//
// Example 2:
//
// Input: flowerbed = [1,0,0,0,1], n = 2
// Output: False
//
//
//
// Note:
//
// The input array won't violate no-adjacent-flowers rule.
// The input array size is in the range of [1, 20000].
// n is a non-negative integer which won't exceed the input array size.
//
//


class Solution {
public:
    //5个位置可以插3个，关键在于1是随机摆放的，说到底，还是要遍历。找0，如果0的左右都为空，则可以放进去，然后前进两次
    bool canPlaceFlowers(vector<int>& flowerbed, int n) 
    {
        if (n == 0) return true;
        if(flowerbed[0]==0&&flowerbed[1]==0) 
        {
            n--;
            flowerbed[0]=1;
        }
        if(flowerbed[flowerbed.size()-1]==0&&flowerbed[flowerbed.size()-2]==0)
        {
            n--;
            flowerbed[flowerbed.size()-1]=1;
        } 
        for (int i = 1; i < flowerbed.size()-1; ++i) 
        {
            if (flowerbed[i] == 0)
            {
                int next =flowerbed[i + 1];
                int pre =flowerbed[i - 1];
                if (next + pre == 0) 
                {
                    flowerbed[i] = 1;
                    --n;
                }
            }
        }
        return n <= 0; 
    }
};

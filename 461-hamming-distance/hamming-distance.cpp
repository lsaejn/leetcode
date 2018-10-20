// The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
//
// Given two integers x and y, calculate the Hamming distance.
//
// Note:
// 0 ≤ x, y < 231.
//
//
// Example:
//
// Input: x = 1, y = 4
//
// Output: 2
//
// Explanation:
// 1   (0 0 0 1)
// 4   (0 1 0 0)
//        ↑   ↑
//
// The above arrows point to positions where the corresponding bits are different.
//
//


class Solution {
public:
    //汉明距离就是其二进制数对应位不同的个数
    //只需异或，然后计算1的个数
    int hammingDistance(int x, int y) {
        bitset<32> i(x);
        bitset<32> j(y);
        bitset<32> re=x^y;
        return re.count();
        
    }
};

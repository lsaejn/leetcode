//
// Given an integer n, return 1 - n in lexicographical order.
//
//
//
// For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].
//
//
//
// Please optimize your algorithm to use less time and space. The input size may be as large as 5,000,000.
//


class Solution {
public:
    //我们希望一次遍历就放入元素。1,10,100,1000,1001,1002,100
    //1,10,11....19 or 1,10,100,101...109,11...110,111....19
    //2,20,21.....29
    //9,90......99
    vector<int> lexicalOrder(int n) 
    {
        vector<int> res(n);
        int cur = 1;
        for (int i = 0; i < n; ++i) 
        {
            res[i] = cur;
            if (cur * 10 <= n)
            {
                cur *= 10;
            } 
            else 
            {
                if (cur >= n) 
                    cur /= 10;
                cur += 1;
                while (cur % 10 == 0) cur /= 10;
            }
        }
        return res;
    }
};

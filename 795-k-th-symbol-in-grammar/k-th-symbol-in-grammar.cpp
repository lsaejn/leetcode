// On the first row, we write a 0. Now in every subsequent row, we look at the previous row and replace each occurrence of 0 with 01, and each occurrence of 1 with 10.
//
// Given row N and index K, return the K-th indexed symbol in row N. (The values of K are 1-indexed.) (1 indexed).
//
//
// Examples:
// Input: N = 1, K = 1
// Output: 0
//
// Input: N = 2, K = 1
// Output: 0
//
// Input: N = 2, K = 2
// Output: 1
//
// Input: N = 4, K = 5
// Output: 1
//
// Explanation:
// row 1: 0
// row 2: 01
// row 3: 0110
// row 4: 01101001
//
//
// Note:
//
//
// 	N will be an integer in the range [1, 30].
// 	K will be an integer in the range [1, 2^(N-1)].
//


class Solution {
public:
    /*
    看到了吗？所有都是反的1和0,把01互换，左边就变成了右边
                0
                01
              01 10
            0110 1001
        01101001 |10010110
01101001 10010110|10010110 01101001
01101001 10010110 10010110 01101001|... 中心对称
注意到，最后0110和1001在复制自己，这个结论是显然的
我们设f(x,y),x是N,y是K,f(x,y)=f(x-1,y/2)
f(4,5)=f(3,2)=f(2,1)=f(1,0)=0
*/    
    //第N(>1)行共有2**(n-1)个元素，前2**(n-2)个由上一层的第一个元素确定
    int getMirror(int x)
    {
        return x==1?0:1;
    }
    int kthGrammar(int N, int K)
    {
        if(N==2&&K==1) return 0;
        if(N==2&&K==2) return 1;
        if(N==1) 
            return 0;
        int num=pow(2,N-1);
        if(K>num/2)//在右半边
            return getMirror(kthGrammar(N,K-num/2));
        else
            return kthGrammar(N-1,K);       
    }
};

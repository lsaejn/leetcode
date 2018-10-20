// We have two integer sequences A and B of the same non-zero length.
//
// We are allowed to swap elements A[i] and B[i].  Note that both elements are in the same index position in their respective sequences.
//
// At the end of some number of swaps, A and B are both strictly increasing.  (A sequence is strictly increasing if and only if A[0] < A[1] < A[2] < ... < A[A.length - 1].)
//
// Given A and B, return the minimum number of swaps to make both sequences strictly increasing.  It is guaranteed that the given input always makes it possible.
//
//
// Example:
// Input: A = [1,3,5,4], B = [1,2,3,7]
// Output: 1
// Explanation: 
// Swap A[3] and B[3].  Then the sequences are:
// A = [1, 3, 5, 7] and B = [1, 2, 3, 4]
// which are both strictly increasing.
//
//
// Note:
//
//
// 	A, B are arrays with the same length, and that length will be in the range [1, 1000].
// 	A[i], B[i] are integer values in the range [0, 2000].
//


class Solution {
public:
    //思路就是：
    //1.对于每对A[i]/B[i],你都可以换或不换,以此进行dp
    //2.我们以{1,3,5,9,7}{4,6,8,10}
    int minSwap(vector<int>& A, vector<int>& B) {
        //初始值，代表第一对元素换和不换的交换次数
        int s = 1, ns = 0; // s -> swap, ns -> not swap
        int ps, pns;       // ps -> previous swap, pns -> previous not swap
        
        for (int i = 1; i < A.size(); ++i) {
            ps = s; pns = ns;
            s = INT_MAX; ns = INT_MAX;
            
            if (A[i] > A[i-1] && B[i] > B[i-1]) {//无非是{1,6},{4,3}和{4,6},{1,3}两组
                // We must swap both or don't swap both
                s = ps + 1;
                ns = pns;
            }
        
            if (A[i] > B[i-1] && B[i] > A[i-1]) {//处理失效的情况{1,6},{4,3}
                // We must swap only one
                s = min(s, pns + 1);
                ns = min(ns, ps);
            }
            //cout << "s:" << s << " ns:" << ns << endl;
        }
        return (min(s, ns));
    }
};

// Given two arrays A and B of equal size, the advantage of A with respect to B is the number of indices i for which A[i] > B[i].
//
// Return any permutation of A that maximizes its advantage with respect to B.
//
//  
//
//
// Example 1:
//
//
// Input: A = [2,7,11,15], B = [1,10,4,11]
// Output: [2,11,7,15]
//
//
//
// Example 2:
//
//
// Input: A = [12,24,8,32], B = [13,25,32,11]
// Output: [24,32,8,12]
//
//
//  
//
// Note:
//
//
// 	1 <= A.length = B.length <= 10000
// 	0 <= A[i] <= 10^9
// 	0 <= B[i] <= 10^9
//
//
//
//


class Solution {
public:
    //这是个田忌赛马的问题，
    //1.我们用最小的代价赢得对比
    //2.然后用最小的代价消耗掉必然会输的对比
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        multiset<int> a(A.begin(), A.end());//获得一个A的排序copy
        vector<int> ans;
        for (int i = 0; i < B.size(); ++i)
        {
            auto it = a.lower_bound(B[i] + 1);//获得第一个不小于b[i]+1的数
            if (it == a.end()) it = a.begin();     //不存在，我们把最小的数消耗掉       
            ans.push_back(*it);
            a.erase(it);
        }
        return ans;
    }
};

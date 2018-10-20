// A sorted list A contains 1, plus some number of primes.  Then, for every p < q in the list, we consider the fraction p/q.
//
// What is the K-th smallest fraction considered?  Return your answer as an array of ints, where answer[0] = p and answer[1] = q.
//
//
// Examples:
// Input: A = [1, 2, 3, 5], K = 3
// Output: [2, 5]
// Explanation:
// The fractions to be considered in sorted order are:
// 1/5, 1/3, 2/5, 1/2, 3/5, 2/3.
// The third fraction is 2/5.
//
// Input: A = [1, 7], K = 1
// Output: [1, 7]
//
//
// Note:
//
//
// 	A will have length between 2 and 2000.
// 	Each A[i] will be between 1 and 30000.
// 	K will be between 1 and A.length * (A.length - 1) / 2.
//


/*
consider an input of [n1, n2, n3, n4, n5], the possible factors are:
[n1/n5, n1/n4, n1/n3, n1/n2, n1/n1]
[n2/n5, n2/n4, n2/n3, n2/n2]
[n3/n5, n3/n4, n3/n3]
[n4/n5, n4/n4]
[n5/n5]
*/
//虽然想到可以用优先队列，但是没想到可以做得这么绝，太绝了，简直无情！！！
//{1,2,3,5,7}
//先放入{1/7,2/7,3/7,5/7,7/7}，最小的数已经在此K=1就在top
//我们要得到K=2，需要将pop一下，把分母的索引-1
//关键在于，我们一定要维护一个大小>=K的队列。
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        priority_queue<pair<double, pair<int,int>>>pq;
        for(int i = 0; i < A.size(); i++)
            pq.push({-1.0*A[i]/A.back(), {i,A.size()-1}});
        while(--K > 0)
        {
            pair<int,int> cur = pq.top().second;
            pq.pop();
            cur.second--;
            pq.push({-1.0*A[cur.first]/A[cur.second], {cur.first, cur.second}});
        }
        return {A[pq.top().second.first], A[pq.top().second.second]};
    }
};
